#include "Menu.h"

Menu::Menu()
{

}

Menu::~Menu()
{
}

bool Menu::IsPlaying()
{
	if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::End))
	{
		return true;
	}

	else
		return false;
}


void Menu::Draw(RenderWindow &window)
{
	window.draw(text);
}