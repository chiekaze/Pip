#include "Enemy.h"
#include <cstdlib>

Enemy::Enemy()
{
	enemyText.loadFromFile("sprites/enemy_ship.png");
	enemyText.setSmooth(false);
	
	enemySprite.setTexture(enemyText);
	enemySprite.setTextureRect(IntRect(0, 0, 32, 32));
	enemySprite.setScale(2, 2);
	enemySprite.setRotation(180);
	enemySprite.setOrigin(15, -5);

	SetPosition();
}

Enemy::~Enemy()
{
	delete playArea;
}

//Enemy boundingbox
FloatRect Enemy::GetEnemyBoundingBox()
{
	return enemyBoundingBox = enemySprite.getGlobalBounds();
}
 
//Randomizes enemy spawn position
void Enemy::SetPosition()
{
	srand(time(NULL));

	enemySprite.setPosition(rand() % 700 + 100, rand() % 1);
}

Vector2f Enemy::GetPosition()
{
	return enemySprite.getPosition();
}

//Checks if enemy collides with the bottom border
bool Enemy::Intersect()
{
	playArea = new PlayArea();

	enemyBoundingBox = enemySprite.getGlobalBounds();

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
	enemySprite.move(Vector2f(0, enemySpeed));
}

void Enemy::Draw(RenderWindow& window)
{
	window.draw(enemySprite);
}