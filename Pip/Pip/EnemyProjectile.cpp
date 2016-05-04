#include "EnemyProjectile.h"

EnemyProjectile::EnemyProjectile()
{
	enemyProjectileText.loadFromFile("sprites/enemy_projectile.png");
	enemyProjectileText.setSmooth(false);

	enemyProjectileSprite.setTexture(enemyProjectileText);
	enemyProjectileSprite.setTextureRect(IntRect(0, 0, 3, 32));
	enemyProjectileSprite.setScale(1, 1);
	enemyProjectileSprite.setRotation(180);

	enemyProjectileSpeed = 7;
	enemyProjectileDamage = 5;
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