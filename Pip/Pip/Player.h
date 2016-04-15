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
	float playerNormalSpeed = 5;
	float playerFocusSpeed = 2.5;

	Player();
	~Player();

	void setPosition();
	Vector2f getPosition();
	
	//void FireProjectile();
	
	void Update();
	void PlayerInput();

	void Draw(RenderWindow& window);
};

#endif;