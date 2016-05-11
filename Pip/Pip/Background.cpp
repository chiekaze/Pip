#include "BackGround.h"

Background::Background(Player* player)
{
	bgNormalSpeed = 1;
	bgSpeed = bgNormalSpeed;

	bg1Tex.loadFromFile("sprites/background.png");
	bg1Tex.setSmooth(false);
	
	bg1Sprite.setTexture(bg1Tex);
	bg1Y = bg1Sprite.getPosition().y;

	bg2Tex.loadFromFile("sprites/background.png");
	bg2Tex.setSmooth(false);
	
	bg2Sprite.setTexture(bg2Tex);
	bg2Y = bg2Sprite.getPosition().y;
	bg2Sprite.setPosition(0, 601);

	mPlayer = player;
}

Background::~Background()
{
}

void Background::Update()
{
	//Background focus speed
	if (mPlayer->PlayerFocus())
	{
		bgSpeed = bgNormalSpeed * mPlayer->GetPlayerFocusFactor();
	}
	else
		bgSpeed = bgNormalSpeed;

	windowBgDiff = bg1Y - 600;

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
		bg2Y = windowBgDiff + 5;
	}
	
	else
	{
		bg2Y += bgSpeed;
	}

	bg1Sprite.setPosition(0, bg1Y);
	bg2Sprite.setPosition(0, bg2Y);

	windowBgDiff = bg1Y - 600;
}
void Background::Draw(RenderWindow &window)
{
	window.draw(bg1Sprite);
	window.draw(bg2Sprite);
}