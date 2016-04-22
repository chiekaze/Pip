#include "Projectile.h"
#include <iostream>

Projectile::Projectile(Player* player)
{
	//projectileShape = CircleShape(projectileSize);
	//projectileShape.setFillColor(Color::Magenta);

	projectileText.loadFromFile("sprites/projectile.png");
	projectileText.setSmooth(false);
	projectileSprite.setTexture(projectileText);
	projectileSprite.setTextureRect(IntRect(0, 0, 3, 32));
	projectileSprite.setScale(1, 1);

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
	projectileSprite.move(Vector2f(0, -projectileSpeed));
}

void Projectile::Draw(RenderWindow& window)
{
	window.draw(projectileSprite);
}