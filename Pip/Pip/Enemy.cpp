#include "Enemy.h"
#include <cstdlib>

Enemy::Enemy()
{
	playArea = new PlayArea();
	enemyShape = CircleShape(enemySize);
	enemyShape.setFillColor(Color::Red);
	setPosition();
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

void Enemy::setPosition()
{
	srand(time(NULL));

	enemyShape.setPosition(rand() % 800, rand() % 1);
}

Vector2f Enemy::getPosition()
{
	return enemyShape.getPosition();
}

bool Enemy::Intersect()
{
	FloatRect enemyBoundingBox = enemyShape.getGlobalBounds();

	if (enemyBoundingBox.intersects(playArea->getBotBoundingBox()))
		return true;

	else
		return false;
}

bool Enemy::isHit()
{
	FloatRect enemyBoundingBox = enemyShape.getGlobalBounds();

	if (enemyBoundingBox.intersects(projectile->getProjectileBox()))
		return true;

	else
		return false;
}

void Enemy::Update()
{
	enemyShape.move(Vector2f(0, enemySpeed));
}

void Enemy::Draw(RenderWindow& window)
{
	window.draw(enemyShape);
}