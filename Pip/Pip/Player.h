#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "PlayArea.h"

using namespace sf;

class Player
{
public:
	CircleShape playerShape;

	PlayArea* playArea;

	float playerSize = 5.0;

	float playerSpeed;
	float playerNormalSpeed = 0.05;
	float playerFocusSpeed = 0.025;

	Player();
	~Player();

	void setPosition();
	Vector2f getPosition();

	void Update();
	void Draw(RenderWindow& window);
};

#endif;