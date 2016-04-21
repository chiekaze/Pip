#include "Projectile.h"
#include <iostream>

Projectile::Projectile(Player* player)
{
	projectileShape = CircleShape(projectileSize);
	projectileShape.setFillColor(Color::Magenta);

	//Sets projectile start position to player position
	if (player)
	{
		setPosition(player->getPosition());
	}
}

Projectile::~Projectile()
{
	delete playArea;
}

FloatRect Projectile::getProjectileBoundingBox()
{
	//Projectile boundingbox
	FloatRect projectileBoundingBox = projectileShape.getGlobalBounds();
	return projectileBoundingBox;
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
	playArea = new PlayArea();

	FloatRect projectileBoundingBox = projectileShape.getGlobalBounds();

	if (projectileBoundingBox.intersects(playArea->getTopBoundingBox()))
		return true;

	else
		return false;
}

int Projectile::projectileDamage()
{
	return projectileDmg;
}

void Projectile::Draw(RenderWindow& window)
{
	window.draw(projectileShape);
}