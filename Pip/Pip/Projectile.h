#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "PlayArea.h"

using namespace sf;

class Projectile
{
public:
	Projectile(Player*);
	~Projectile();

	int projectileDamage();

	FloatRect getProjectileBox();
	void setPosition(Vector2f);
	void Update();
	bool Intersect();
	void Draw(RenderWindow& window);

private:
	PlayArea* playArea;

	CircleShape projectileShape;
	FloatRect projectileBoundingBox;

	int projectileSize = 2;
	int projectileSpeed = 15;
};

#endif