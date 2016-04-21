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

	FloatRect GetEnemyBoundingBox();
	void SetPosition();
	Vector2f GetPosition();
	bool Intersect();
	int GetEnemyHP();
	void TakeDamage(int damage);
	bool IsDead();
	void Update();
	void Draw(RenderWindow& window);

private:
	PlayArea* playArea;
	Projectile* projectile;

	CircleShape enemyShape;	
	FloatRect enemyBoundingBox;

	int enemySize = 10;
	int enemySpeed = 2;
	int enemyHp = 10;
};
#endif