#include "Menu.h"
#include <iostream>

Menu::Menu()
{
	isPlaying = false;
	font.loadFromFile("fonts/Minecraft.ttf");
	text.setFont(font);
	text.setString("Press End to play game");
	text.setCharacterSize(22);
	text.setPosition(Vector2f(400, 300));
}

Menu::~Menu()
{
}

bool Menu::IsPlaying()
{
	return isPlaying;
}

void Menu::Update()
{
	if (Keyboard::isKeyPressed(Keyboard::End))
	{
		isPlaying = true;
	}

	else
		isPlaying = false;
}


void Menu::Draw(RenderWindow &window)
{
	window.draw(text);
}