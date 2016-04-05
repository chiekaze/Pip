#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "PlayArea.h"

using namespace sf;

class Game
{
public:
	RenderWindow* window;
	Player* player;
	PlayArea* playArea;

	Clock clock;
	//Clock deltaTime;

	int windowWidth = 800;
	int windowHeight = 600;

	Game();
	~Game();

	void Update();
	void Draw();
};

#endif;