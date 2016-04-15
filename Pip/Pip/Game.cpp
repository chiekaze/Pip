#include "Game.h"
#include <iostream>

Game::Game()
{
	window = new RenderWindow(VideoMode(windowWidth, windowHeight), "Pip");
	
	player = new Player();
	playArea = new PlayArea();
}

Game::~Game()
{
	delete window;
	delete player;
	delete playArea;
}

void Game::Update()
{
	while (window->isOpen())
	{
		window->setFramerateLimit(60);
		window->setVerticalSyncEnabled(1);

		window->setKeyRepeatEnabled(false);
		player->Update();
		
		Event event;

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

		player->Update();
		
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

	player->Draw(*window);
	playArea->Draw(*window);
	
	window->display();
}