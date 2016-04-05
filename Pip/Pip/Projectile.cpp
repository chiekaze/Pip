#include "Projectile.h"
#include <iostream>

Projectile::Projectile()
{
	projectileShape = CircleShape(projectileSize);
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

void Projectile::projectileMove(Clock& clock)
{
	//Projectile moves
	projectileShape.move(Vector2f(0, -projectileSpeed * clock.getElapsedTime().asSeconds()));
}

void Projectile::Draw(RenderWindow& window)
{
	window.draw(projectileShape);
}