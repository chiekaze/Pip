#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "PlayArea.h"

using namespace sf;

class Projectile
{
public:
	PlayArea* playArea;
	CircleShape projectileShape;

	FloatRect getProjectileBox();
	FloatRect projectileBoundingBox;
	
	float projectileSize = 2;
	float projectileSpeed = 15;

	//int projectileDamage = 10;

	Projectile(Player*);
	~Projectile();

	void setPosition(Vector2f);
	bool Intersect();

	void Update();
	void Draw(RenderWindow& window);
};

#endif