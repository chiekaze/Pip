#include "Projectile.h"
#include <iostream>

Projectile::Projectile(Player* player)
{
	playArea = new PlayArea();
	playArea->setPositions();

	projectileShape = CircleShape(projectileSize);
	projectileShape.setFillColor(Color::Magenta);

	//Sets projecteil start position to player position
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

//Projectile moves
void Projectile::Update()
{
	projectileShape.move(Vector2f(0, -projectileSpeed));
}

//Projectile collision check with top border
bool Projectile::Intersect()
{
	FloatRect projectileBoundingBox = projectileShape.getGlobalBounds();

	if (projectileBoundingBox.intersects(playArea->getTopBoundingBox()))
		return true;

	else
		return false;
}

void Projectile::Draw(RenderWindow& window)
{
	window.draw(projectileShape);
}