#include "Asteroid.h"

Asteroid::Asteroid(Player* player)
{
	mPlayer = player;

	asteroidText.loadFromFile("sprites/health_pack.png");
	asteroidText.setSmooth(false);

	asteroidHurtText.loadFromFile("sprites/health_pack.png");
	asteroidHurtText.setSmooth(false);

	asteroidSprite.setTexture(asteroidText);
	asteroidSprite.setTextureRect(IntRect(0, 0, 32, 32));
	asteroidSprite.setScale(3, 3);
	asteroidSprite.setOrigin(16, 16);

	asteroidNormalSpeed = 2;
	asteroidSpeed = asteroidNormalSpeed;
	asteroidSideNormal = 1;
	asteroidSideSpeed = asteroidSideNormal;
	asteroidHP = 100;
	asteroidDMG = 25;

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

bool Asteroid::Intersect()
{
	playArea = new PlayArea();

	asteroidBoundingBox = asteroidSprite.getGlobalBounds();

	if (asteroidBoundingBox.intersects(playArea->GetBottomBoundingBox()))
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

	asteroidSprite.setTexture(asteroidText);
	asteroidSprite.move(Vector2f(asteroidSideSpeed, asteroidSpeed));
}

void Asteroid::Draw(RenderWindow& window)
{
	window.draw(asteroidSprite);
}