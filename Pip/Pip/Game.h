#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "Player.h"
#include "PlayArea.h"
#include "Projectile.h"
#include "Enemy.h"

using namespace sf;

class Game
{
public:
	Game();
	~Game();

	void Update();
	void Draw();

private:
	Projectile* projectile;
	std::vector<Projectile*> projectiles;

	Event event;

	RenderWindow* window;
	Player* player;
	PlayArea* playArea;

	Enemy* enemy;
	std::vector<Enemy*> enemies;

	int windowWidth = 800;
	int windowHeight = 600;

};

#endif;