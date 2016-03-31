#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Enemy
{
public:
	Enemy(int size, float speed, int HP);
	~Enemy(void);

	void setEnemySpeed(float speed);
	void setEnemySize(int size);
	void setEnemyHP(int HP);

	void setFillColor(Color);
	void setPosition(int x, int y);

private:
	int enemySize;
	int enemySpeed;
	int enemyHP;

	int xPos;
	int yPos;
};

#endif