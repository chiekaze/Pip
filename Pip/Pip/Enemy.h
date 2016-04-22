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
	int GetEnemyDamage();
	void TakeDamage(int damage);
	bool IsDead();
	void Update();
	void Draw(RenderWindow& window);

private:
	PlayArea* playArea;
	Projectile* projectile;

	Texture enemyText;
	RectangleShape enemyShape;	
	Sprite enemySprite;
	Vector2f enemySize;

	FloatRect enemyBoundingBox;

	int enemySpeed = 2;
	int enemyHp = 10;
	int enemyDMG = 5;
};
#endif