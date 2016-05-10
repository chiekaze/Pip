#include "Enemy.h"

Enemy::Enemy(Player* player)
{
	enemyText.loadFromFile("sprites/enemy_ship.png");
	enemyText.setSmooth(false);

	enemyHurtText.loadFromFile("sprites/enemy_ship_damage.png");
	enemyHurtText.setSmooth(false);
	
	enemySprite.setTexture(enemyText);
	enemySprite.setTextureRect(IntRect(0, 0, 32, 32));
	enemySprite.setScale(2, 2);
	enemySprite.setRotation(180);
	enemySprite.setOrigin(15, -5);

	enemyNormalSpeed = 2;
	enemySpeed = enemyNormalSpeed;
	enemyHp = 100;
	enemyDMG = 5;

	mPlayer = player;

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
	enemySprite.setPosition(rand() % 600 + 100, rand() % 1);
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
	enemySprite.setTexture(enemyHurtText);
	enemyHp -= damage;
}

void Enemy::SetSprite()
{
	enemySprite.setTexture(enemyText);
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
	//Enemy focus speed
	if (mPlayer->PlayerFocus())
	{
		enemySpeed = enemyNormalSpeed * mPlayer->GetPlayerFocusFactor();
	}
	else
		enemySpeed = enemyNormalSpeed;

	enemySprite.setTexture(enemyText);
	enemySprite.move(Vector2f(0, enemySpeed));
}

void Enemy::Draw(RenderWindow& window)
{
	window.draw(enemySprite);
}