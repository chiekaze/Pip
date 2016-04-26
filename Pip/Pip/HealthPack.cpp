#include "HealthPack.h"
#include <cstdlib>
#include <math.h>

HealthPack::HealthPack()
{
	healthText.loadFromFile("sprites/projectile.png");
	healthText.setSmooth(false);

	healthSprite.setTexture(healthText);
	healthSprite.setTextureRect(IntRect(0, 0, 32, 32));
	healthSprite.setScale(0.7 , 0.7);

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
	srand(time(NULL));

	healthSprite.setPosition(rand() % 700 + 100, rand() % 1);
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