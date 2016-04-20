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

int Enemy::EnemyHP()
{
	return enemyHp;
}

void Enemy::TakeDamage(int damage)
{
	enemyHp -= damage;
}

bool Enemy::isDead()
{
	if (enemyHp <= 0)
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