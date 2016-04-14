#include "Projectile.h"
#include <iostream>

Projectile::Projectile(Player* player)
{
	playArea = new PlayArea();
	playArea->setPositions();

	projectileShape = CircleShape(projectileSize);

	if (player)
	{
		setPosition(player->getPosition());
	}
}

FloatRect Projectile::getProjectileBox()
{
	//Projectile boundingbox
	FloatRect projectileBoundingBox = projectileShape.getGlobalBounds();
	return projectileBoundingBox;
}

Projectile::~Projectile()
{
}

void Projectile::setPosition(Vector2f position)
{
	projectileShape.setPosition(position);
}

Vector2f Projectile::getProjectilePosition()
{
	return projectileShape.getPosition();
}

void Projectile::Update()
{
	//Projectile moves
	projectileShape.move(Vector2f(0, -projectileSpeed));
}

bool Projectile::Intersect()
{
	FloatRect projectileBoundingBox = projectileShape.getGlobalBounds();

	if (projectileBoundingBox.intersects(playArea->getTopBoundingBox()))
	{
		return true;
	}

	else
		return false;
}

void Projectile::Draw(RenderWindow& window)
{
	window.draw(projectileShape);
}