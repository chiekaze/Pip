#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "Player.h"
#include "PlayArea.h"
#include "Projectile.h"

using namespace sf;

class Game
{
public:
	RenderWindow* window;
	Player* player;
	PlayArea* playArea;
	Projectile* projectile;

	std::vector<Projectile*> projectiles;

	int windowWidth = 800;
	int windowHeight = 600;

	Game();
	~Game();

	void Update();
	void Draw();
};

#endif;