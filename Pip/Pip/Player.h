#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "PlayArea.h"
#include "Projectile.h"

using namespace sf;

class Player
{
public:
	CircleShape playerShape;

	PlayArea* playArea;
	Projectile* projectile;

	float playerSize = 5.0;

	int playerSpeed;
	int playerNormalSpeed = 2500;
	int playerFocusSpeed = 1000;

	Player();
	~Player();

	void setPosition();
	Vector2f getPosition();

	void Update(Clock& clock);
	void Draw(RenderWindow& window);
};

#endif;