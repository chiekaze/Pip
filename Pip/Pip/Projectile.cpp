#include "Projectile.h"
#include <iostream>

Projectile::Projectile(Player* player)
{
	projectileShape = CircleShape(projectileSize);

	if (player)
	{
		setPosition(player->getPosition());
	}
}

//FloatRect Projectile::getProjectileBox()
//{
//	//Projectile boundingbox
//	FloatRect projectileBoundingBox = projectileShape.getGlobalBounds();
//	return projectileBoundingBox;
//}

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

void Projectile::Update(Clock& clock)
{
	//Projectile moves
	projectileShape.move(Vector2f(0, -projectileSpeed * clock.getElapsedTime().asSeconds()));
}

void Projectile::Draw(RenderWindow& window)
{
	window.draw(projectileShape);
}