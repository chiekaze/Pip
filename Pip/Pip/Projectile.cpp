#include "Projectile.h"
#include <iostream>

Projectile::Projectile()
{
	player = new Player();
	projectileShape = CircleShape(projectileSize);
	projectileShape.setPosition(400, 300);
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

void Projectile::setPosition()
{
	projectileShape.setPosition(player->getPosition());
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