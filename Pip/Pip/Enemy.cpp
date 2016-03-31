#include "Enemy.h";

Enemy::Enemy(int size, float speed, int HP)
{
	size = enemySize;
	speed = enemySpeed;
	HP = enemyHP;
}

void Enemy::setEnemySize(int size)
{
	enemySize = size;
}

void Enemy::setEnemySpeed(float speed)
{
	enemySpeed = speed;
}

void Enemy::setEnemyHP(int HP)
{
	enemyHP = HP;
}

void Enemy::setFillColor(Color)
{}

void Enemy::setPosition(int x, int y)
{
	xPos = x;
	yPos = y;
}