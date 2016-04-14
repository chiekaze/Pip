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

	int playerSpeed;
	int playerNormalSpeed = 2500;
	int playerFocusSpeed = 1000;
	Vector2f playerPos;


	Player();
	~Player();

	void setPosition();
	Vector2f getPosition();

	void Update(Clock& clock);
	void Draw(RenderWindow& window);
};

#endif;