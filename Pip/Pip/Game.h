#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "Player.h"
#include "PlayArea.h"
#include "Projectile.h"
#include "Enemy.h"
#include "Background.h"
#include "Starfield.h"

using namespace sf;

class Game
{
public:
	Game();
	~Game();

	void Update();
	void Draw();

private:
	RenderWindow* window;
	Player* player;
	PlayArea* playArea;
	Background* bg;
	Starfield* sf;

	Projectile* projectile;
	std::vector<Projectile*> projectiles;

	Enemy* enemy;
	std::vector<Enemy*> enemies;
	
	Event event;

	int windowWidth = 800;
	int windowHeight = 600;

	int score = 0;
};

#endif;