#include "ElapsedTime.h"
#include <string>
#include <iostream>

ElapsedTime::ElapsedTime()
{
	font.loadFromFile("fonts/Minecraft.ttf");
	text.setFont(font); text.setString(std::to_string(playTime.asSeconds()));
	text.setCharacterSize(22);
	text.setPosition(Vector2f(700, 5));
}

ElapsedTime::~ElapsedTime()
{

}

void ElapsedTime::Update()
{
	playTime = clock.getElapsedTime();
	text.setString(std::to_string(playTime.asSeconds()));
}

void ElapsedTime::Draw(RenderWindow &window)
{
	window.draw(text);
}