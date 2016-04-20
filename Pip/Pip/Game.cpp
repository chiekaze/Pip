#include "Game.h"
#include <iostream>

Game::Game()
{
	window = new RenderWindow(VideoMode(windowWidth, windowHeight), "Pip");
	player = new Player();
	playArea = new PlayArea();
	enemy = new Enemy();
}

Game::~Game()
{
	delete window;
	delete player;
	delete playArea;
}

void Game::Update()
{
	enemy = new Enemy();
	enemies.push_back(enemy);

	while (window->isOpen())
	{
		window->setFramerateLimit(60);
		window->setVerticalSyncEnabled(1);
		window->setKeyRepeatEnabled(false);

		player->Update();

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
				if (enemy->getEnemyBox().intersects(projectile->getProjectileBox()))
				{
					std::cout << "Enemy is kill!\n";
					enemy->TakeDamage(projectile->projectileDamage());
					std::cout << enemy->EnemyHP() << "\n";
				}
			}

			if (enemy->isDead())
			{
				enemies.erase(enemies.begin());
				enemy = new Enemy();
				enemies.push_back(enemy);
				std::cout << "Enemy " << enemies.size() << "\n";
			}
			
		}
	
		Draw();
	}
}

void Game::Draw()
{
	window->clear();

	//Draws projectiles
	for (auto projectile : projectiles)
	{
		projectile->Draw(*window);
	}

	for (auto enemy : enemies)
	{
		enemy->Draw(*window);
	}

	player->Draw(*window);
	playArea->Draw(*window);
	
	window->display();
}