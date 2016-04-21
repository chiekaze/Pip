#include "Enemy.h"
#include <cstdlib>

Enemy::Enemy()
{
	enemyShape = CircleShape(enemySize);
	enemyShape.setFillColor(Color::Red);
	setPosition();
}

Enemy::~Enemy()
{
	delete playArea;
}

//Enemy boundingbox
FloatRect Enemy::getEnemyBox()
{
	return enemyBoundingBox = enemyShape.getGlobalBounds();
}

//Randomizes enemy spawn position
void Enemy::setPosition()
{
	srand(time(NULL));

	enemyShape.setPosition(rand() % 800, rand() % 1);
}

Vector2f Enemy::getPosition()
{
	return enemyShape.getPosition();
}

//Checks if enemy collides with the bottom border
bool Enemy::Intersect()
{
	playArea = new PlayArea();

	enemyBoundingBox = enemyShape.getGlobalBounds();

	if (enemyBoundingBox.intersects(playArea->getBotBoundingBox()))
		return true;

	else
		return false;
}

int Enemy::getEnemyHP()
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