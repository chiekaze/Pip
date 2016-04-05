#include "Game.h"

Game::Game()
{
	window = new RenderWindow(VideoMode(windowWidth, windowHeight), "Pip");
	player = new Player();
	//enemy = new Enemy();
	//projectile = new Projectile();
	playArea = new PlayArea();
	playArea->setPositions();

	//Sets player start position
	player->setPosition();

	//Sets enemy start position
	//enemy->setStartPosition();

	clock.restart();
}

Game::~Game()
{
	delete window;
	delete player;
	delete playArea;
	//delete enemy;
	//delete projectile;
}

void Game::Update()
{
	while (window->isOpen())
	{
		Event event;

		while (window->pollEvent(event))
		{
			if ((event.type == sf::Event::Closed) || (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
			{
				window->close();
			}
		}

		player->Update(clock);
		//enemy->Update(clock);
		//projectile->Update(clock);
		Draw();
		clock.restart();
	}
}

void Game::Draw()
{
	window->clear();
	player->Draw(*window);
	playArea->Draw(*window);
	//enemy->Draw(*window);
	//projectile->Draw(*window);
	window->display();
}