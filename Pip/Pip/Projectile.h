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

	int GetProjectileDamage();
	FloatRect GetProjectileBoundingBox();
	void SetPosition(Vector2f);
	bool Intersect();
	void Update();
	void Draw(RenderWindow& window);

private:
	PlayArea* playArea;

	CircleShape projectileShape;
	FloatRect projectileBoundingBox;

	int projectileSize = 4;
	int projectileSpeed = 15;
	int projectileDamage = 5;
};

#endif