#include "ElapsedTime.h"
#include <string>
#include <iostream>

ElapsedTime::ElapsedTime()
{
	menu = new Menu();

	font.loadFromFile("fonts/Minecraft.ttf");
	text.setFont(font);
	text.setCharacterSize(22);
	text.setPosition(Vector2f(700, 5));

	mClockReset = false;
	playTime = clock.getElapsedTime();

	if (menu->IsPlaying())
	{
		text.setString("TIME: " + std::to_string((int)floorf(playTime.asSeconds()))); // <-- This shit turns the time value into an int
	}
}

ElapsedTime::~ElapsedTime()
{

}

int ElapsedTime::getElapsedTime()
{
	playTime = clock.getElapsedTime();
	return (int)floorf(playTime.asSeconds());
}

void ElapsedTime::Update()
{
	//Starting playtime from zero
	if (!mClockReset) {
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