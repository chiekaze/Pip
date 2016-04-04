#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;

class Game
{
public:
	RenderWindow* window;
	Player* player;
	
	Clock clock;
	Clock deltaTime;

	int windowWidth = 800;
	int windowHeight = 600;

	Game();
	~Game();

	void Update();
	void Draw();
};

#endif;