#include "Background.h"

Background::Background()
{
	bg1Tex.loadFromFile("sprites/background.png");
	bg1Tex.setSmooth(false);
	bg1Sprite.setTexture(bg1Tex);
	
	bg1Y = bg1Sprite.getPosition().y;

	bg2Tex.loadFromFile("sprites/background.png");
	bg2Tex.setSmooth(false);
	bg2Sprite.setTexture(bg2Tex);
	bg2Sprite.setPosition(0, 601);

	bg2Y = bg2Sprite.getPosition().y;
}


void Background::Update()
{
	windowbg1diff = bg1Y - 600;

	if (bg1Y >= 600)
	{
		bg1Y = -590;
	}
	
	else
	{
		bg1Y += bgSpeed;
	}

	if (bg2Y >= 600)
	{
		bg2Y = -600;
	}
	
	else if (bg2Y < bg1Y)
	{
		bg2Y = windowbg1diff + 5;
	}
	
	else
	{
		bg2Y += bgSpeed;
	}

	bg1Sprite.setPosition(0, bg1Y);
	bg2Sprite.setPosition(0, bg2Y);

	windowbg1diff = bg1Y - 600;
}
void Background::Draw(sf::RenderWindow &window)
{
	window.draw(bg1Sprite);
	window.draw(bg2Sprite);
}