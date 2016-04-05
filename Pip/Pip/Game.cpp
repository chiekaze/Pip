#include "Game.h"

Game::Game()
{
	window = new RenderWindow(VideoMode(windowWidth, windowHeight), "Pip");
	player = new Player();
	playArea = new PlayArea();
	playArea->setPositions();

	//Sets player start position
	player->setPosition();

	clock.restart();
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
		Event event;

		while (window->pollEvent(event))
		{
			if ((event.type == sf::Event::Closed) || (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
			{
				window->close();
			}
		}

		player->Update(clock);
		Draw();
		clock.restart();
	}
}

void Game::Draw()
{
	window->clear();
	player->Draw(*window);
	playArea->Draw(*window);
	window->display();
}