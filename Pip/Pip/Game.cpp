#include "Game.h"
#include <iostream>
#include <cstdlib>

Game::Game()
{
	srand(time(NULL));

	windowWidth = 800;
	windowHeight = 600;

	window = new RenderWindow(VideoMode(windowWidth, windowHeight), "Pip");
	player = new Player();
	playArea = new PlayArea();
	bg = new Background(player);
	sf = new Starfield(player);
	elapsedTime = new ElapsedTime();
	scoreTxt = new ScoreText();
	soundManager = new SoundManager();
	menu = new Menu(player);

	projectileTimer = 0;
	healthTimer = 0;
	spawnTimer = 0;
	asteroidTimer = 0;

	spawnTimerValue = spawnTimerNormal;
	spawnTimerNormal = 5;
	spawnTimerFocus = spawnTimerNormal / player->GetPlayerFocusFactor();
	lastSpawnTimerUpdate = 0;
	spawnRateTime = 20;

	asteroidTimerValue = asteroidTimerNormal;
	asteroidTimerNormal = 10;
	asteroidTimerFocus = asteroidTimerNormal / player->GetPlayerFocusFactor();
	lastAsteroidUpdate = 0;
	asteroidTime = 30;

	healthTop = 30;
	healthBottom = 10;
	healthTimerAddition = 20;

	healthTimerValue = rand() % healthTop + healthBottom;
	lastHealthTimerUpdate = 0;
	healthTime = healthTop;

	score = 0;
}

Game::~Game()
{
	delete window;
	delete player;
	delete playArea;
	delete bg;
	delete sf;
	delete scoreTxt;
	delete elapsedTime;
	delete soundManager;
	delete menu;
}

//Increases the spawn rate of enemies after a set amount of time
void Game::UpdateSpawnTimer()
{
	if (menu->IsPlaying())
	{
		if (player->PlayerFocus())
		{
			spawnTimerValue = spawnTimerFocus;
			asteroidTimerValue = asteroidTimerFocus;
		}
		
		else
		{
			spawnTimerValue = spawnTimerNormal;
			asteroidTimerValue = asteroidTimerNormal;
		}

		if (spawnTimerValue >= 2)
		{
			if (elapsedTime->getElapsedTime() - lastSpawnTimerUpdate >= spawnRateTime)
			{
				spawnTimerNormal -= 1;
				spawnTimerValue = spawnTimerNormal;
				spawnTimerFocus = spawnTimerNormal / player->GetPlayerFocusFactor();
				lastSpawnTimerUpdate = elapsedTime->getElapsedTime();
			}
		}

		if (asteroidTimerValue >= 2)
		{
			if (elapsedTime->getElapsedTime() - lastAsteroidUpdate >= asteroidTime)
			{
				asteroidTimerNormal -= 1;
				asteroidTimerValue = asteroidTimerNormal;
				asteroidTimerFocus = asteroidTimerNormal / player->GetPlayerFocusFactor();
				lastAsteroidUpdate = elapsedTime->getElapsedTime();
			}
		}

		if (healthTimerValue <= 120)
		{
			if (elapsedTime->getElapsedTime() - lastHealthTimerUpdate >= healthTime)
			{
				healthTop += healthTimerAddition;
				healthBottom += healthTimerAddition;
				healthTime = healthTop;
				healthTimerValue = rand() % healthTop + healthBottom;
				lastHealthTimerUpdate = elapsedTime->getElapsedTime();
			}
		}
	}
}

void Game::Update()
{
	SoundBuffer buffer;
	Sound sound;

	if (menu->IsPlaying())
	{
		elapsedTime = new ElapsedTime();

		//Spawns enemy when game starts
		enemy = new Enemy(player);
		enemies.push_back(enemy);

		//Spawns enemy projectiles when game starts
		enemyprojectile = new EnemyProjectile(player);
		enemyprojectiles.push_back(enemyprojectile);

		for (auto enemy : enemies)
		{
			for (auto enemyprojectile : enemyprojectiles)
			{
				if (enemy)
				{
					enemyprojectile->setPosition(enemy->GetPosition());
				}
			}
		}
	}

	while (window->isOpen())
	{
		if (menu->IsNotPlaying())
		{
			menu->Update();
		}

		spawnTimer += 1 / 60.0f;
		healthTimer += 1 / 60.0f;
		asteroidTimer += 1 / 60.0f;

		if (player->GetPlayerHP() <= 0)
		{
			elapsedTime->Reset();
		}

		if (menu->IsPlaying())
		{
			UpdateSpawnTimer();

			//Enemy spawn timer
			if ((spawnTimer > spawnTimerValue))
			{
				spawnTimer = 0;
				enemy = new Enemy(player);
				enemies.push_back(enemy);
			}

			//Asteroid spawn timer
			if (asteroidTimer > asteroidTimerValue)
			{
				
				asteroidTimer = 0;
				asteroid = new Asteroid(player);
				asteroids.push_back(asteroid);
				
			}

			//Healthpack spawn timer
			if ((healthTimer > healthTimerValue))
			{
				healthTimer = 0;

				healthpack = new HealthPack(player);
				healthpacks.push_back(healthpack);
			}

			player->Update();
			elapsedTime->Update();

			//PROJECTILE UPDATES
			for (auto projectile : projectiles)
			{
				//Collision checking and projectile movement
				projectile->Update();

				if (projectile->Intersect())
				{
					//Deletes projectiles from vector after colliding
					projectiles.erase(projectiles.begin());
				}
			}
			//PROJECTILE ENDS HERE

			//HEALTHPACK UPDATES
			for (auto healthpack : healthpacks)
			{
				//Collision checking and movement
				healthpack->Update();

				if (healthpack->Intersect())
				{
					healthpacks.erase(healthpacks.begin());
				}

				//Checking if player collides with healthpack
				if (healthpack->GetHealthPackBoundingBox().intersects(player->GetPlayerBoundingBox()))
				{
					player->TakeHealth(healthpack->GetHealth());
					soundManager->HealthPickupSound();
					healthpacks.erase(healthpacks.begin());
				}
			}
			//HEALTHPACK ENDS HERE

			//ENEMYPROJECTILE UPDATES
			for (auto enemyprojectile : enemyprojectiles)
			{
				enemyprojectile->Update();

				//Checks if enemy projectile collides with bottom border of the screen
				if (enemyprojectile->Intersect())
				{
					enemyprojectiles.erase(enemyprojectiles.begin());
				}

				//Checks if enemy projectile collides with player
				if (enemyprojectile->GetEnemyProjectileBoundingBox().intersects(player->GetPlayerBoundingBox()))
				{
					//Deletes enemy projectile when hits player
					enemyprojectiles.erase(enemyprojectiles.begin());

					player->TakeDamage(enemyprojectile->GetEnemyDamage());

					//Plays player hurt sound
					soundManager->PlayerHurt();

					//Plays player death sound
					if (player->GetPlayerHP() <= 0)
					{

						enemies.erase(enemies.begin());
					}
				}
			}
			//ENEMYPROJECTILE ENDS HERE

			//ENEMY UPDATES
			for (auto enemy : enemies)
			{
				enemy->Update();

				//Enemyprojectile timer
				projectileTimer += 1 / 60.0f;

				if (projectileTimer > 1)
				{
					projectileTimer = 0;

					enemyprojectile = new EnemyProjectile(player);
					enemyprojectiles.push_back(enemyprojectile);
					enemyprojectile->setPosition(enemy->GetPosition());
				}

				//Checks if an enemy collides with the bottom border, then deletes it and spawns a new one 
				if (enemy->Intersect())
				{
					enemies.erase(enemies.begin());
				}

				//Checks if enemy is hit by projectile
				for (auto projectile : projectiles)
				{
					if (enemy->GetEnemyBoundingBox().intersects(projectile->GetProjectileBoundingBox()))
					{
						enemy->TakeDamage(projectile->GetProjectileDamage());

						//Deletes projectiles from vector after colliding
						projectiles.erase(projectiles.begin());
					}
				}

				//Deletes killed enemy and adds 1 score
				if (enemy->IsDead())
				{
					enemies.erase(enemies.begin());

					//Playes enemy death sound
					soundManager->EnemyDeathSound();

					scoreTxt->Update();
				}

				//Checks if player collides with enemy and gives damage to player
				if (player->GetPlayerBoundingBox().intersects(enemy->GetEnemyBoundingBox()))
				{
					//Deletes enemy when player collides with it
					enemies.erase(enemies.begin());
					soundManager->EnemyDeathSound();

					player->TakeDamage(enemy->GetEnemyDamage());
				}
			}
			//ENEMY ENDS HERE

			//ASTEROID UPDATES
			for (auto asteroid : asteroids)
			{
				asteroid->Update();

				//Deletes asteroid if collides with bottom border
				if (asteroid->Intersect())
				{
					asteroids.erase(asteroids.begin());
				}

				//Checks if asteroid is hit by projectiles
				for (auto projectile : projectiles)
				{
					if (asteroid->GetAsteroidBoundingBox().intersects(projectile->GetProjectileBoundingBox()))
					{
						asteroid->TakeDamage(projectile->GetProjectileDamage());

						projectiles.erase(projectiles.begin());
					}
				}

				//Deletes destroyed asteroid and adds 1 point
				if (asteroid->IsDestroyed())
				{
					asteroids.erase(asteroids.begin());
					soundManager->AsteroidExplosion();

					scoreTxt->Update();
				}

				//Checks if player is hit by asteroid and gives damage to player
				if (player->GetPlayerBoundingBox().intersects(asteroid->GetAsteroidBoundingBox()))
				{
					asteroids.erase(asteroids.begin());
					soundManager->AsteroidExplosion();

					player->TakeDamage(asteroid->GetAsteroidDamage());
				}
			}
			//ASTEROID ENDS HERE
		}

		window->setFramerateLimit(60);
		window->setVerticalSyncEnabled(1);
		window->setKeyRepeatEnabled(false);

		bg->Update();
		sf->Update();

		while (window->pollEvent(event))
		{
			if ((event.type == sf::Event::Closed) ||
				(event.type == sf::Event::KeyPressed) &&
				(event.key.code == sf::Keyboard::Escape))
			{
				window->close();
			}

			//Shooting
			if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Space) && menu->IsPlaying())
			{
				soundManager->ProjectileSound();
				projectile = new Projectile(player);
				projectiles.push_back(projectile);
			}
		}

		Draw();
	}
}

void Game::Draw()
{
	window->clear(Color::Black);

	bg->Draw(*window);
	sf->Draw(*window);
	menu->Draw(*window);
	
	if (player->IsDead())
	{
		menu->UpdateDeadMenu();
		menu->DrawDeadMenu(*window);
	}

	if (menu->IsPlaying())
	{
		bg->Draw(*window);
		sf->Draw(*window);

		for (auto healthpack : healthpacks)
		{
			healthpack->Draw(*window);
		}

		for (auto projectile : projectiles)
		{
			projectile->Draw(*window);
		}

		for (auto enemy : enemies)
		{
			enemy->Draw(*window);
		}

		for (auto enemyprojectile : enemyprojectiles)
		{
			enemyprojectile->Draw(*window);
		}

		for (auto asteroid : asteroids)
		{
			asteroid->Draw(*window);
		}

		player->Draw(*window);
		playArea->Draw(*window);
		scoreTxt->Draw(*window);
		elapsedTime->Draw(*window);
	}
	
	window->display();
}