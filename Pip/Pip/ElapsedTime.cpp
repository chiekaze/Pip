#include "ElapsedTime.h"
#include <string>
#include <iostream>

ElapsedTime::ElapsedTime()
{
	font.loadFromFile("fonts/Minecraft.ttf");
	text.setFont(font);
	text.setString("TIME: " + std::to_string((int)floorf(playTime.asSeconds()))); // <-- This shit turns the time value into an int
	text.setCharacterSize(22);
	text.setPosition(Vector2f(700, 5));
}

ElapsedTime::~ElapsedTime()
{

}

void ElapsedTime::Update()
{
	playTime = clock.getElapsedTime();
	text.setString("TIME: " + std::to_string((int)floorf(playTime.asSeconds())));
}

void ElapsedTime::Draw(RenderWindow &window)
{
	window.draw(text);
}