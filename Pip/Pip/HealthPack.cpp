#include "HealthPack.h"
#include <cstdlib>
#include <math.h>

HealthPack::HealthPack()
{
	healthText.loadFromFile("sprites/health_pack.png");
	healthText.setSmooth(false);
	healthSprite.setTexture(healthText);
	healthSprite.setTextureRect(IntRect(0, 0, 32, 32));
	healthSprite.setScale(1 , 1);
	healthSprite.setOrigin(15, 5);

	healthSpeed = 1.7;
	health = 25;

	SetPosition();
}

HealthPack::~HealthPack()
{
	delete playArea;
}

//Healthpack boundingbox
FloatRect HealthPack::GetHealthPackBoundingBox()
{
	return healthBoundingBox = healthSprite.getGlobalBounds();
}

//Sets spawn point randomly
void HealthPack::SetPosition()
{
	healthSprite.setPosition(rand() % 600 + 100, rand() % 10);
}

bool HealthPack::Intersect()
{
	playArea = new PlayArea();

	healthBoundingBox = healthSprite.getGlobalBounds();

	if (healthBoundingBox.intersects(playArea->GetBottomBoundingBox()))
	{
		return true;
	}
	else
		return false;
}

//Returns health points
int HealthPack::GetHealth()
{
	return health;
}

void HealthPack::Update()
{
	healthSprite.move(Vector2f(0, healthSpeed));
}

void HealthPack::Draw(RenderWindow& window)
{
	window.draw(healthSprite);
}