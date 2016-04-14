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
	delete projectile;
}

void Game::Update()
{
	while (window->isOpen())
	{
<<<<<<< HEAD
		window->setFramerateLimit(0);
		window->setVerticalSyncEnabled(0);
		
=======

>>>>>>> cb5efada8c9f21118f6bad88fe1280a308e10e2c
		Event event;

		while (window->pollEvent(event))
		{

			if ((event.type == sf::Event::Closed) || 
				(event.type == sf::Event::KeyPressed) && 
				(event.key.code == sf::Keyboard::Escape))
			{
				window->close();
			}

			if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Space))
			{
				
				projectile = new Projectile(player);
				projectiles.push_back(projectile);
				
				std::cout << "BANG " << projectiles.size() << "\n";
			}
		}
		
		for (auto projectile : projectiles)
		{
			projectile->Update();
			if (projectile->Intersect())
			{
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

	for (auto projectile : projectiles)
	{
		projectile->Draw(*window);
	}

	player->Draw(*window);
	playArea->Draw(*window);
	
	window->display();
}