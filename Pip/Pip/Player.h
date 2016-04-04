#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
public:
	CircleShape playerShape;
	
	float playerSize = 5;
	
	int playerSpeed;
	int playerNormalSpeed = 2500;
	int playerFocusSpeed = 1000;

	Player();
	~Player();

	void Update(Clock& clock);
	void Draw(RenderWindow& window);
};

#endif;