#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include "Projectile.h"

using namespace sf;

class Enemy
{
public:
	CircleShape enemyShape;

	FloatRect getEnemyBox();

	Projectile* projectile;

	std::vector<Enemy*> enemies;

	float enemySize = 5.0;
	int enemySpeed = 2500;
	int enemyHP = 100;

	Enemy();
	~Enemy();

	void setStartPosition();
	Vector2f getPosition();

	//void Update(Clock& clock);
	void Draw(RenderWindow& window);
};
#endif