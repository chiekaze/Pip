#ifndef ENEMYPROJECTILE_H
#define ENEMYPROJECTILE_H

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <vector>

using namespace sf;

class EnemyProjectile
{
public:
	EnemyProjectile();
	~EnemyProjectile();

	int GetEnemyDamage();
	FloatRect GetEnemyProjectileBoundingBox();
	void setPosition(Vector2f);
	bool Intersect();
	void Update();
	void Draw(RenderWindow& window);

private:
	PlayArea* playarea;

	Texture enemyProjectileText;
	Sprite enemyProjectileSprite;

	int enemyProjectileSpeed = 7;
	int enemyProjectileDamage = 5;

	Enemy* enemy;
	std::vector<Enemy*> enemies;
};

#endif