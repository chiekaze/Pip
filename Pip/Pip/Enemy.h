#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include "PlayArea.h"
#include <math.h>

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
	int GetEnemyDamage();
	void TakeDamage(int damage);
	bool IsDead();
	void Update();
	void Draw(RenderWindow& window);

	float projectileTimer;

private:
	PlayArea* playArea;

	Texture enemyText;
	Sprite enemySprite;

	FloatRect enemyBoundingBox;

	int enemySpeed = 2;
	int enemyHp = 100;
	int enemyDMG = 5;
};
#endif