#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include "PlayArea.h"
#include "Player.h"

using namespace sf;

class Enemy
{
public:
	Enemy(Player* player);
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
	Player* mPlayer;

	Texture enemyText;
	Texture enemyHurtText;
	Sprite enemySprite;

	FloatRect enemyBoundingBox;

	float enemySpeed;
	float enemyNormalSpeed;
	int enemyHp;
	int enemyDMG;
};
#endif