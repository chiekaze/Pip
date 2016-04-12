#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Projectile
{
public:
	CircleShape projectileShape;

	FloatRect getProjectileBox();

	float projectileSize = 2.5;
	int projectileSpeed = 2500;
	int projectileDamage = 10;

	Projectile();
	~Projectile();

	//void setPosition();
	Vector2f getProjectilePosition();

	void Update(Clock& clock);
	void Draw(RenderWindow& window);
};

#endif