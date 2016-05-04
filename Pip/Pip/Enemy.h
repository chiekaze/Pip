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
	void SetSprite();
	bool IsDead();
	void Update();
	void Draw(RenderWindow& window);

private:
	PlayArea* playArea;

	Texture enemyText;
	Texture enemyHurtText;
	Sprite enemySprite;

	FloatRect enemyBoundingBox;

	int enemySpeed;
	int enemyHp;
	int enemyDMG;
};
#endif