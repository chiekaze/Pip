#include "StarField.h"

Starfield::Starfield(Player* player)
{
	mPlayer = player;

	starNormalSpeed = 1.3;
	starSpeed = starNormalSpeed;

	star1Tex.loadFromFile("sprites/starfield.png");
	star1Tex.setSmooth(false);

	star1Sprite.setTexture(star1Tex);
	sf1Y = star1Sprite.getPosition().y;

	star2Tex.loadFromFile("sprites/starfield.png");
	star2Tex.setSmooth(false);

	star2Sprite.setTexture(star2Tex);
	sf2Y = star2Sprite.getPosition().y;
	star2Sprite.setPosition(0, 601);
}

Starfield::~Starfield()
{
}

void Starfield::Update()
{
	//Starfield focus speed
	if (mPlayer->PlayerFocus())
	{
		starSpeed = starNormalSpeed * mPlayer->GetPlayerFocusFactor();
	}
	else
		starSpeed = starNormalSpeed;

	windowBgDiff = sf1Y - 600;

	if (sf1Y >= 600)
	{
		sf1Y = -590;
	}

	else
	{
		sf1Y += starSpeed;
	}

	if (sf2Y >= 600)
	{
		sf2Y = -600;
	}

	else if (sf2Y < sf1Y)
	{
		sf2Y = windowBgDiff + 5;
	}

	else
	{
		sf2Y += starSpeed;
	}

	star1Sprite.setPosition(0, sf1Y);
	star2Sprite.setPosition(0, sf2Y);

	windowBgDiff = sf1Y - 600;
}
void Starfield::Draw(sf::RenderWindow &window)
{
	window.draw(star1Sprite);
	window.draw(star2Sprite);
}