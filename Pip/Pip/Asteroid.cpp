#include "Asteroid.h"

Asteroid::Asteroid(Player* player)
{
	mPlayer = player;

	asteroidText.loadFromFile("sprites/asteroid2.png");
	asteroidText.setSmooth(false);

	asteroidHurtText.loadFromFile("sprites/asteroid2.png");
	asteroidHurtText.setSmooth(false);

	

	asteroidSprite.setTexture(asteroidText);
	asteroidSprite.setTextureRect(IntRect(0, 0, 64, 64));
	asteroidSprite.setScale(asteroidScale, asteroidScale);
	asteroidSprite.setOrigin(32, 32);

	asteroidNormalSpeed = 2;
	asteroidSpeed = asteroidNormalSpeed;
	asteroidSideNormal = rand() % (3 + 1) - 2;
	asteroidSideSpeed = asteroidSideNormal;
	asteroidHP = 200;
	asteroidDMG = 25;

	if (asteroidSideNormal == 0)
	{
		asteroidSideNormal += 1;
	}

	SetScale();
	SetPosition();
}

Asteroid::~Asteroid()
{
	delete playArea;
}

FloatRect Asteroid::GetAsteroidBoundingBox()
{
	return asteroidBoundingBox = asteroidSprite.getGlobalBounds();
}

void Asteroid::SetPosition()
{
	asteroidSprite.setPosition(rand() % 600 + 100, rand() % 1);
}

void Asteroid::SetScale()
{
	asteroidScale = rand() % 2 + 1;
	asteroidSprite.setScale(asteroidScale, asteroidScale);
}

bool Asteroid::Intersect()
{
	playArea = new PlayArea();

	asteroidBoundingBox = asteroidSprite.getGlobalBounds();

	if (asteroidBoundingBox.intersects(playArea->GetEnemyBorderBoundingBox()))
		return true;
	else
		return false;
}

int Asteroid::GetAsteroidHP()
{
	return asteroidHP;
}

int Asteroid::GetAsteroidDamage()
{
	return asteroidDMG;
}

void Asteroid::TakeDamage(int damage)
{
	asteroidSprite.setTexture(asteroidHurtText);
	asteroidHP -= damage;
}

bool Asteroid::IsDestroyed()
{
	if (asteroidHP <= 0)
		return true;
	else
		return false;
}

void Asteroid::Update()
{
	if (mPlayer->PlayerFocus())
	{
		asteroidSpeed = asteroidNormalSpeed * mPlayer->GetPlayerFocusFactor();
		asteroidSideSpeed = asteroidSideNormal * mPlayer->GetPlayerFocusFactor();
	}
	else
	{
		asteroidSpeed = asteroidNormalSpeed;
		asteroidSideSpeed = asteroidSideNormal;
	}

	asteroidSprite.rotate(1);
	asteroidSprite.setTexture(asteroidText);
	asteroidSprite.move(Vector2f(asteroidSideSpeed, asteroidSpeed));
}

void Asteroid::Draw(RenderWindow& window)
{
	window.draw(asteroidSprite);
}