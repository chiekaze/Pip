#include "Enemy.h"
#include <cstdlib>

Enemy::Enemy()
{
	enemyShape = CircleShape(enemySize);
	enemyShape.setFillColor(Color::Red);
	SetPosition();
}

Enemy::~Enemy()
{
	delete playArea;
}

//Enemy boundingbox
FloatRect Enemy::GetEnemyBoundingBox()
{
	return enemyBoundingBox = enemyShape.getGlobalBounds();
}

//Randomizes enemy spawn position
void Enemy::SetPosition()
{
	srand(time(NULL));

	enemyShape.setPosition(rand() % 800, rand() % 1);
}

Vector2f Enemy::GetPosition()
{
	return enemyShape.getPosition();
}

//Checks if enemy collides with the bottom border
bool Enemy::Intersect()
{
	playArea = new PlayArea();

	enemyBoundingBox = enemyShape.getGlobalBounds();

	if (enemyBoundingBox.intersects(playArea->GetBottomBoundingBox()))
		return true;

	else
		return false;
}

int Enemy::GetEnemyHP()
{
	return enemyHp;
}

int Enemy::GetEnemyDamage()
{
	return enemyDMG;
}

void Enemy::TakeDamage(int damage)
{
	enemyHp -= damage;
}

bool Enemy::IsDead()
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