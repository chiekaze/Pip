#include "Projectile.h"
#include <iostream>

Projectile::Projectile(Player* player)
{
	projectileNormalSpeed = 15;
	projectileSpeed = projectileNormalSpeed;
	projectileDamage = 25;

	projectileText.loadFromFile("sprites/projectile.png");
	projectileText.setSmooth(false);
	
	projectileSprite.setTexture(projectileText);
	projectileSprite.setTextureRect(IntRect(0, 0, 3, 32));
	projectileSprite.setScale(1, 1);

	mPlayer = player;

	//Sets projectile start position to player position
	if (mPlayer)
	{
		SetPosition(mPlayer->GetPosition());
	}
}

Projectile::~Projectile()
{
	delete playArea;
}

int Projectile::GetProjectileDamage()
{
	return projectileDamage;
}

FloatRect Projectile::GetProjectileBoundingBox()
{
	//Projectile boundingbox
	FloatRect projectileBoundingBox = projectileSprite.getGlobalBounds();
	return projectileBoundingBox;
}

void Projectile::SetPosition(Vector2f position)
{
	projectileSprite.setPosition(position);
}

//Projectile collision check with top border
bool Projectile::Intersect()
{
	playArea = new PlayArea();

	FloatRect projectileBoundingBox = projectileSprite.getGlobalBounds();

	if (projectileBoundingBox.intersects(playArea->GetTopBoundingBox()))
		return true;

	else
		return false;
}

//Projectile moves
void Projectile::Update()
{
	//Projectile focus speed
	if (mPlayer->PlayerFocus())
	{
		projectileSpeed = projectileNormalSpeed * mPlayer->GetPlayerFocusFactor();
	}
	else
		projectileSpeed = projectileNormalSpeed;

	projectileSprite.move(Vector2f(0, -projectileSpeed));
}

void Projectile::Draw(RenderWindow& window)
{
	window.draw(projectileSprite);
}