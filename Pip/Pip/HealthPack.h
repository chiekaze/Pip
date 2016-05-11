#ifndef HEALTHPACK_H
#define HEALTHPACK_H

#include <SFML/Graphics.hpp>
#include "PlayArea.h"
#include "Player.h"

using namespace sf;

class HealthPack
{
public:
	HealthPack(Player* player);
	~HealthPack();

	FloatRect GetHealthPackBoundingBox();
	void SetPosition();
	bool Intersect();
	int GetHealth();

	void Update();
	void Draw(RenderWindow& window);

private:
	PlayArea* playArea;
	Player* mPlayer;

	Texture healthText;
	Sprite healthSprite;

	FloatRect healthBoundingBox;

	float healthSpeed;
	float healthNormalSpeed;
	int health;

	Clock clock;
};

#endif