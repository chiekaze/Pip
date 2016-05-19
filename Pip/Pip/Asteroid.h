#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>
#include "PlayArea.h"
#include "Player.h"

using namespace sf;

class Asteroid
{
public:
	Asteroid(Player* player);
	~Asteroid();

	FloatRect GetAsteroidBoundingBox();
	void SetPosition();
	bool Intersect();
	int GetAsteroidHP();
	int GetAsteroidDamage();
	int GetScore();
	void TakeDamage(int damage);
	void SetSprite();
	bool IsDestroyed();
	void SetScale();

	void Update();
	void Draw(RenderWindow& window);

private:
	PlayArea* playArea;
	Player* mPlayer;

	Texture asteroidText;
	Texture asteroidHurtText;
	Sprite asteroidSprite;

	FloatRect asteroidBoundingBox;

	int asteroidScale;
	float asteroidSpeed;
	float asteroidNormalSpeed;
	float asteroidSideSpeed;
	float asteroidSideNormal;

	int asteroidHP;
	int asteroidDMG;
	int asteroidScore;
};

#endif