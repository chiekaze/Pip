#include "EnemyProjectile.h"

EnemyProjectile::EnemyProjectile()
{
	enemyProjectileText.loadFromFile("sprites/projectile.png");
	enemyProjectileText.setSmooth(false);

	enemyProjectileSprite.setTexture(enemyProjectileText);
	enemyProjectileSprite.setTextureRect(IntRect(0, 0, 3, 32));
	enemyProjectileSprite.setScale(1, 1);

	//Sets start position as enemy position
	for (auto enemy : enemies)
	{
		if (enemy)
		{
			setPosition(enemy->GetPosition());
		}
	}
}

EnemyProjectile::~EnemyProjectile()
{
	delete playarea;
}

int EnemyProjectile::GetEnemyDamage()
{
	return enemyProjectileDamage;
}

FloatRect EnemyProjectile::GetEnemyProjectileBoundingBox()
{
	//Enemy projectile boundingbox
	FloatRect enemyProjectileBoundingBox = enemyProjectileSprite.getGlobalBounds();
	return enemyProjectileBoundingBox;
}

void EnemyProjectile::setPosition(Vector2f position)
{
	enemyProjectileSprite.setPosition(position);
}

//Enemy projectile collision with bottom border
bool EnemyProjectile::Intersect()
{
	playarea = new PlayArea();

	FloatRect enemyProjectileBoundingBox = enemyProjectileSprite.getGlobalBounds();

	if (enemyProjectileBoundingBox.intersects(playarea->GetBottomBoundingBox()))
		return true;

	else
		return false;
}

//Enemy projectile moves
void EnemyProjectile::Update()
{
	enemyProjectileSprite.move(Vector2f(0, enemyProjectileSpeed));
}

void EnemyProjectile::Draw(RenderWindow& window)
{
	window.draw(enemyProjectileSprite);
}