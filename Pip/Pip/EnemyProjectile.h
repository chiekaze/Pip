#ifndef ENEMYPROJECTILE_H
#define ENEMYPROJECTILE_H

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Player.h"
#include <vector>

using namespace sf;

class EnemyProjectile
{
public:
	EnemyProjectile(Player* player);
	~EnemyProjectile();

	int GetEnemyDamage();
	FloatRect GetEnemyProjectileBoundingBox();
	void setPosition(Vector2f);
	bool Intersect();
	void Update();
	void Draw(RenderWindow& window);

private:
	PlayArea* playarea;
	Player* mPlayer;

	Texture enemyProjectileText;
	Sprite enemyProjectileSprite;

	float enemyProjectileSpeed;
	float enemyProjectileNormalSpeed;
	int enemyProjectileDamage;

	Enemy* enemy;
	std::vector<Enemy*> enemies;
};

#endif