#include "ElapsedTime.h"
#include <string>
#include <iostream>

ElapsedTime::ElapsedTime()
{
	font.loadFromFile("fonts/Minecraft.ttf");
	text.setFont(font);
	text.setCharacterSize(22);
	text.setPosition(Vector2f(700, 5));

	mClockReset = false;
	playTime = clock.getElapsedTime();
}

ElapsedTime::~ElapsedTime()
{
}

int ElapsedTime::getElapsedTime()
{
	playTime = clock.getElapsedTime();
	return (int)floorf(playTime.asSeconds());
}

void ElapsedTime::Reset()
{
	clock.restart();
	playTime = clock.getElapsedTime();

}

void ElapsedTime::Update()
{
	//Starting playtime from zero
	if (!mClockReset) 
	{
		clock.restart();
		mClockReset = true;
	}

	playTime = clock.getElapsedTime();
	text.setString("TIME: " + std::to_string((int)floorf(playTime.asSeconds())));

	if (floorf(playTime.asSeconds()) > 99)
	{
		text.setPosition(Vector2f(690, 5));
	}

	if (floorf(playTime.asSeconds()) > 999)
	{
		text.setPosition(Vector2f(675, 5));
	}
}

void ElapsedTime::Draw(RenderWindow &window)
{
	window.draw(text);
}