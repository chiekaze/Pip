#ifndef HEALTHPACK_H
#define HEALTHPACK_H

#include <SFML/Graphics.hpp>
#include "PlayArea.h"

using namespace sf;

class HealthPack
{
public:
	HealthPack();
	~HealthPack();

	FloatRect GetHealthPackBoundingBox();
	void SetPosition();
	bool Intersect();
	int GetHealth();

	void Update();
	void Draw(RenderWindow& window);

private:
	PlayArea* playArea;

	Texture healthText;
	Sprite healthSprite;

	FloatRect healthBoundingBox;

	int healthSpeed = 2;
	int health = 25;

	Clock clock;
};

#endif