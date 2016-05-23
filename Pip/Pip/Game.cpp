#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

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
	menu = new Menu(player,scoreTxt);

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
	mute = false;

	font.loadFromFile("fonts/Minecraft.ttf");
	text.setString("SOUNDS OFF");
	text.setFont(font); text.setCharacterSize(20);
	text.setPosition(Vector2f(665, 570));
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
		//Hardlocking the spawnrates after a certain amount of time
		if (elapsedTime->getElapsedTime() >= 100)
		{
			spawnTimerNormal = 1;
			spawnTimerFocus = 2;
			asteroidTimerNormal = 1;
			asteroidTimerFocus = 2;
			healthTimerValue = 100;
		}

		else
		{
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
	}
}

void Game::Mute()
{
	window->setKeyRepeatEnabled(false);

	if (!mute)
	{
		if (event.type == Event::KeyReleased && event.key.code == Keyboard::LShift)
		{
			mute = true;
		}
	}

	if (mute)
	{
		if (event.type == Event::KeyReleased && event.key.code == Keyboard::RShift)
		{
			mute = false;
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

		Mute();

		spawnTimer += 1 / 60.0f;
		healthTimer += 1 / 60.0f;
		asteroidTimer += 1 / 60.0f;

		if (player->IsDead())
		{
			elapsedTime->Reset();
			scoreTxt->writeScore();
			menu->UpdateDeadMenu();
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
			for (auto pIt = projectiles.begin(); pIt != projectiles.end(); ++pIt)
			{
				//Projectile iterator
				Projectile *projectile = *pIt;

				//Collision checking and projectile movement
				projectile->Update();

				if (projectile->Intersect())
				{
					//Deletes projectiles from vector after colliding
					pIt = projectiles.erase(pIt);
					pIt--;
					continue;
				}
			}
			//PROJECTILE ENDS HERE

			//HEALTHPACK UPDATES
			for (auto hIt = healthpacks.begin(); hIt != healthpacks.end(); ++hIt)
			{
				//Healthpack iterator
				HealthPack *healthpack = *hIt;

				//Collision checking and movement
				healthpack->Update();

				if (healthpack->Intersect())
				{
					hIt = healthpacks.erase(hIt);
					hIt--;
					continue;
				}

				//Checking if player collides with healthpack
				if (healthpack->GetHealthPackBoundingBox().intersects(player->GetPlayerBoundingBox()))
				{
					player->TakeHealth(healthpack->GetHealth());
					if (!mute)
					{
						soundManager->HealthPickupSound();
					}
					hIt = healthpacks.erase(hIt);
					hIt--;
					continue;
				}
			}
			//HEALTHPACK ENDS HERE

			//ENEMYPROJECTILE UPDATES
			for (auto eIt = enemyprojectiles.begin(); eIt != enemyprojectiles.end(); ++eIt)
			{
				//Enemyprojectile iterator
				EnemyProjectile *enemyprojectile = *eIt;

				enemyprojectile->Update();

				//Checks if enemy projectile collides with bottom border of the screen
				if (enemyprojectile->Intersect())
				{
					eIt = enemyprojectiles.erase(eIt);
					eIt--;
					continue;
				}

				//Checks if enemy projectile collides with player
				if (enemyprojectile->GetEnemyProjectileBoundingBox().intersects(player->GetPlayerBoundingBox()))
				{
					player->TakeDamage(enemyprojectile->GetEnemyDamage());

					//Plays player hurt sound
					if (!mute)
					{
						soundManager->PlayerHurt();
					}

					//Deletes enemy projectile when hits player
					eIt = enemyprojectiles.erase(eIt);
					eIt--;
					continue;
				}
			}
			//ENEMYPROJECTILE ENDS HERE

			//ENEMY UPDATES
			for (auto it = enemies.begin(); it != enemies.end(); ++it)
			{
				//Enemy iterator
				Enemy *enemy = *it;

				enemy->Update();

				//Checks if an enemy collides with the bottom border, then deletes it and spawns a new one 
				if (enemy->Intersect())
				{
					it = enemies.erase(it);
					it--;
					continue;
				}

				projectileTimer += 1 / 60.0f;

				if (projectileTimer > 1)
				{
					projectileTimer = 0;

					enemyprojectile = new EnemyProjectile(player);
					enemyprojectiles.push_back(enemyprojectile);
					enemyprojectile->setPosition(enemy->GetPosition());
				}

				//Checks if enemy is hit by projectile
				for (auto pIt = projectiles.begin(); pIt != projectiles.end(); ++pIt)
				{
					Projectile *projectile = *pIt;

					if (enemy->GetEnemyBoundingBox().intersects(projectile->GetProjectileBoundingBox()))
					{
						enemy->TakeDamage(projectile->GetProjectileDamage());

						//Deletes projectiles from vector after colliding
						pIt = projectiles.erase(pIt);
						pIt--;
						continue;
					}
				}

				//Deletes killed enemy and adds points
				if (enemy->IsDead())
				{
					it = enemies.erase(it);
					it--;

					//Playes enemy death sound
					if (!mute)
					{
						soundManager->EnemyDeathSound();
					}

					scoreTxt->addScore(enemy->GetScore());

					continue;
				}

				//Checks if player collides with enemy and gives damage to player
				if (player->GetPlayerBoundingBox().intersects(enemy->GetEnemyBoundingBox()))
				{
					//Deletes enemy when player collides with it
					if (!mute)
					{
						soundManager->EnemyDeathSound();
					}

					player->TakeDamage(enemy->GetEnemyDamage());
					it = enemies.erase(it);
					it--;
					continue;
				}
			}
			//ENEMY ENDS HERE

			//ASTEROID UPDATES
			for (auto aIt = asteroids.begin(); aIt != asteroids.end(); ++aIt)
			{
				//Asteroid iterator
				Asteroid *asteroid = *aIt;

				asteroid->Update();

				//Deletes asteroid if collides with bottom border
				if (asteroid->Intersect())
				{
					aIt = asteroids.erase(aIt);
					aIt--;
					continue;
				}

				//Checks if asteroid is hit by projectiles
				for (auto pIt = projectiles.begin(); pIt != projectiles.end(); ++pIt)
				{
					Projectile *projectile = *pIt;

					if (asteroid->GetAsteroidBoundingBox().intersects(projectile->GetProjectileBoundingBox()))
					{
						asteroid->TakeDamage(projectile->GetProjectileDamage());

						pIt = projectiles.erase(pIt);
						pIt--;
						continue;
					}
				}

				//Deletes destroyed asteroid and adds points
				if (asteroid->IsDestroyed())
				{
					aIt = asteroids.erase(aIt);
					aIt--;
					if (!mute)
					{
						soundManager->AsteroidExplosion();
					}

					scoreTxt->addScore(asteroid->GetScore());
					continue;
				}

				//Checks if player is hit by asteroid and gives damage to player
				if (player->GetPlayerBoundingBox().intersects(asteroid->GetAsteroidBoundingBox()))
				{
					aIt = asteroids.erase(aIt);
					aIt--;
					if (!mute)
					{
						soundManager->AsteroidExplosion();
					}

					player->TakeDamage(asteroid->GetAsteroidDamage());
					continue;
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
				remove("kebab.txt");
				window->close();
			}

			//Shooting
			if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Space) && menu->IsPlaying())
			{
				if (!mute)
				{
					soundManager->ProjectileSound();
				}
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

		if (mute)
		{
			window->draw(text);
		}
	}
	
	window->display();
}