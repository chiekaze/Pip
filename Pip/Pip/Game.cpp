#include "Game.h"
#include <iostream>

Game::Game()
{
	window = new RenderWindow(VideoMode(windowWidth, windowHeight), "Pip");
	player = new Player();
	playArea = new PlayArea();
	bg = new Background();
	sf = new Starfield();
	scoreTxt = new ScoreText();
	elapsedTime = new ElapsedTime();

	clock.restart();
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
}

void Game::Update()
{
	SoundBuffer buffer;
	Sound sound;

	//Spawns enemy when game starts
	enemy = new Enemy();
	enemies.push_back(enemy);
	
	//Spawns enemy projectiles when game starts(?)
	enemyprojectile = new EnemyProjectile();
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

	std::cout << "Enemy " << enemies.size() << "\n";
	std::cout << "Enemy HP: " << enemy->GetEnemyHP() << "\n";

	while (window->isOpen())
	{
		Time elapsed = clock.getElapsedTime();

		//std::cout << elapsed.asSeconds() << "\n";

		window->setFramerateLimit(60);
		window->setVerticalSyncEnabled(1);
		window->setKeyRepeatEnabled(false);

		bg->Update();
		sf->Update();
		player->Update();
		elapsedTime->Update();

		while (window->pollEvent(event))
		{
			if ((event.type == sf::Event::Closed) ||
				(event.type == sf::Event::KeyPressed) &&
				(event.key.code == sf::Keyboard::Escape))
			{
				window->close();
			}

			//Shooting
			if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Space))
			{
				projectile = new Projectile(player);
				projectiles.push_back(projectile);

				std::cout << "BANG " << projectiles.size() << "\n";
			}
		}

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

		for (auto enemy : enemies)
		{
			enemy->Update();

			//Checks if an enemy collides with the bottom border, then deletes it and spawns a new one 
			if (enemy->Intersect())
			{
				enemies.erase(enemies.begin());
				enemy = new Enemy();
				enemies.push_back(enemy);

				std::cout << "Enemy " << enemies.size() << "\n";
			}

			//Checks if enemy is hit by projectile
			for (auto projectile : projectiles)
			{
				if (enemy->GetEnemyBoundingBox().intersects(projectile->GetProjectileBoundingBox()))
				{
					std::cout << "Enemy Hit!\n";
					enemy->TakeDamage(projectile->GetProjectileDamage());

					std::cout << "Enemy HP: " << enemy->GetEnemyHP() << "\n";

					//Deletes projectiles from vector after colliding
					projectiles.erase(projectiles.begin());
				}
			}

			//Updates and spawns enemy projectiles
			for (auto enemyprojectile : enemyprojectiles)
			{
				enemyprojectile->Update();

				//Checks if enemy projectile collides with bottom border of the screen
				if (enemyprojectile->Intersect())
				{
					enemyprojectiles.erase(enemyprojectiles.begin());

					enemyprojectile = new EnemyProjectile();
					enemyprojectiles.push_back(enemyprojectile);
					enemyprojectile->setPosition(enemy->GetPosition());
				}

				//Checks if enemy projectile collides with player
				if (enemyprojectile->GetEnemyProjectileBoundingBox().intersects(player->GetPlayerBoundingBox()))
				{
					//Deletes enemy projectile when hits player
					enemyprojectiles.erase(enemyprojectiles.begin());
					enemyprojectile = new EnemyProjectile();
					enemyprojectiles.push_back(enemyprojectile);
					enemyprojectile->setPosition(enemy->GetPosition());

					player->TakeDamage(enemyprojectile->GetEnemyDamage());
					std::cout << player->GetPlayerHP() << std::endl;

					//Plays player hurt sound
					buffer.loadFromFile("sounds/playerhurt.wav");
					sound.setBuffer(buffer);
					sound.play();

					//HUEHUEHUEHUEHUE
					if (player->GetPlayerHP() == 5)
					{
						buffer.loadFromFile("sounds/playerdeath.wav");
						sound.setBuffer(buffer);
						sound.play();
					}

					if (player->IsDead())
					{
						window->close();
					}
				}
			}

			//Deletes killed enemy, spawns a new one and adds 1 score
			if (enemy->IsDead())
			{
				enemies.erase(enemies.begin());

				//Playes enemy death sound
				//soundManager->EnemyDeathSound();
				buffer.loadFromFile("sounds/explosion1.wav");
				sound.setBuffer(buffer);
				sound.play();
				std::cout << "Sound played!\n";

				enemy = new Enemy();
				enemies.push_back(enemy);

				scoreTxt->Update();

				std::cout << "Enemy killed!\n";
				std::cout << "Enemy " << enemies.size() << "\n";
			}

			//Checks if player collides with enemy and gives damage to player
			if (player->GetPlayerBoundingBox().intersects(enemy->GetEnemyBoundingBox()))
			{
				//Deletes enemy when player collides with it
				enemies.erase(enemies.begin());
				enemy = new Enemy();
				enemies.push_back(enemy);

				player->TakeDamage(enemy->GetEnemyDamage());
				std::cout << player->GetPlayerHP() << std::endl;

				if (player->IsDead())
				{
					buffer.loadFromFile("sounds/playerdeath.wav");
					sound.setBuffer(buffer);
					sound.play();
					std::cout << "You're fucking dead m8!\n";
					window->close();
				}
			}
		}

		Draw();
	}

}

void Game::Draw()
{
	window->clear();
	
	bg->Draw(*window);
	sf->Draw(*window);
	
	//Draws projectiles
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

	scoreTxt->Draw(*window);
	elapsedTime->Draw(*window);
	playArea->Draw(*window);
	player->Draw(*window);
	
	window->display();
}