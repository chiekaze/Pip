#include "Menu.h"
#include <iostream>

Menu::Menu()
{
	isPlaying = false;
	font.loadFromFile("fonts/Minecraft.ttf");

	title.setFont(font);
	start.setFont(font);
	quit.setFont(font);
	controls.setFont(font);
	move.setFont(font);
	shoot.setFont(font);
	focus.setFont(font);

	//TITLE
	title.setString("PIP: THE GAME");
	title.setCharacterSize(64);
	title.setPosition(Vector2f(160, 100));

	//START
	start.setString("PRESS 'ENTER' TO START");
	start.setCharacterSize(24);
	start.setPosition(Vector2f(230, 300));

	//QUIT
	quit.setString("PRESS 'ESC' TO QUIT");
	quit.setCharacterSize(24);
	quit.setPosition(Vector2f(260, 340));

	//CONTROLS TITLE
	controls.setString("CONTROLS:");
	controls.setCharacterSize(24);
	controls.setPosition(Vector2f(320, 420));

	//CONTROLS
	move.setString("MOVE - ARROW KEYS");
	move.setCharacterSize(16);
	move.setPosition(Vector2f(310, 460));

	shoot.setString("SHOOT - SPACE");
	shoot.setCharacterSize(16);
	shoot.setPosition(Vector2f(330, 480));

	focus.setString("FOCUS - LEFT CTRL");
	focus.setCharacterSize(16);
	focus.setPosition(Vector2f(315, 500));
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
	if (Keyboard::isKeyPressed(Keyboard::Return))
	{
		isPlaying = true;
	}

	else
		isPlaying = false;
}

void Menu::Draw(RenderWindow &window)
{
	window.draw(title);
	window.draw(start);
	window.draw(quit);
	window.draw(controls);
	window.draw(move);
	window.draw(shoot);
	window.draw(focus);
}