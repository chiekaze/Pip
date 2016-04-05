#include "Enemy.h"

Enemy::Enemy()
{
	enemyShape = CircleShape(enemySize);
	enemyShape.setFillColor(Color::Red);
}

Enemy::~Enemy()
{
}

FloatRect Enemy::getEnemyBox()
{
	//Enemy boundingbox
	FloatRect enemyBoundingBox = enemyShape.getGlobalBounds();

	return enemyBoundingBox;
}

void Enemy::setStartPosition()
{
	enemyShape.setPosition(800 - 100, 600 / 2);
}

Vector2f Enemy::getPosition()
{
	return enemyShape.getPosition();
}

void Enemy::Update(Clock& clock)
{
	enemyShape.move(Vector2f(0, enemySpeed * clock.getElapsedTime().asSeconds()));

	//Getting hit by projectile (this needs to be done better at some point)
	if (getEnemyBox().intersects(projectile->getProjectileBox()))
	{
		enemyHP -= projectile->projectileDamage;
	}
}

void Enemy::Draw(RenderWindow& window)
{
	window.draw(enemyShape);
}