#include "Projectile.h"
#include <iostream>

Projectile::Projectile(Player* player)
{
	projectileShape = CircleShape(projectileSize);
	projectileShape.setFillColor(Color::Magenta);

	//Sets projectile start position to player position
	if (player)
	{
		SetPosition(player->GetPosition());
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
	FloatRect projectileBoundingBox = projectileShape.getGlobalBounds();
	return projectileBoundingBox;
}

void Projectile::SetPosition(Vector2f position)
{
	projectileShape.setPosition(position);
}

//Projectile collision check with top border
bool Projectile::Intersect()
{
	playArea = new PlayArea();

	FloatRect projectileBoundingBox = projectileShape.getGlobalBounds();

	if (projectileBoundingBox.intersects(playArea->GetTopBoundingBox()))
		return true;

	else
		return false;
}

//Projectile moves
void Projectile::Update()
{
	projectileShape.move(Vector2f(0, -projectileSpeed));
}

void Projectile::Draw(RenderWindow& window)
{
	window.draw(projectileShape);
}