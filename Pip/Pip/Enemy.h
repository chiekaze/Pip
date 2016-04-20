#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include "PlayArea.h"
#include "Projectile.h"

using namespace sf;

class Enemy
{
public:
	Enemy();
	~Enemy();

	FloatRect getEnemyBox();

	void setPosition();
	Vector2f getPosition();

	int EnemyHP();
	void TakeDamage(int damage);

	bool isDead();
	bool Intersect();
	void Update();
	void Draw(RenderWindow& window);

private:
	CircleShape enemyShape;
	PlayArea* playArea;
	Projectile* projectile;

	int enemySize = 10;
	int enemySpeed = 2;
	int enemyHp = 10;
};
#endif