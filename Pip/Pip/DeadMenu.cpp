#include "DeadMenu.h"

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
	if (Keyboard::isKeyPressed(Keyboard::Return))
	{
		isplaying = true;
	}

	else
		isplaying = false;
}

void DeadMenu::Draw(RenderWindow &window)
{
	window.draw(dead);
	window.draw(score);
}