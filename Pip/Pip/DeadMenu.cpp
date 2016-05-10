#include "DeadMenu.h"
#include <iostream>

DeadMenu::DeadMenu()
{
	font.loadFromFile("fonts/Minecraft.ttf");

	dead.setFont(font);
	score.setFont(font);

	//DEAD
	dead.setString("UR DED M8");
	dead.setCharacterSize(64);
	dead.setPosition(Vector2f(160, 100));

	//SCORE
	score.setString("FINAL SCORE: " + std::to_string(scoretext->getScore()));
	score.setCharacterSize(22);
	score.setPosition(Vector2f(5, 5));

	//RESTART
	restart.setString("PRESS 'ENTER' TO RESTART");
	restart.setCharacterSize(22);
	restart.setPosition(Vector2f(5, 5));
}

DeadMenu::~DeadMenu()
{
}

bool DeadMenu::isPlaying()
{
	return isplaying;
}

void DeadMenu::Update()
{
	if (player->IsDead())
	{
		menu->stopPlaying();

		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			menu->Update();
		}
	}
}

void DeadMenu::Draw(RenderWindow &window)
{
	if (player->IsDead())
	{
		window.draw(dead);
		window.draw(score);
		window.draw(restart);

		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			std::cout << "You fugged-ed up";
		}
	}
}