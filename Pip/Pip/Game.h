#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "PlayArea.h"
#include "Projectile.h"
#include <vector>
#include <iostream>
#include <thread>

using namespace sf;

class Game
{
public:
	RenderWindow* window;
	Player* player;
	PlayArea* playArea;
	Projectile* projectile;

	std::vector<Projectile*> projectiles;

	Clock clock;

	int windowWidth = 800;
	int windowHeight = 600;

	Game();
	~Game();

	/*
	void shoot(){
		projectile = new Projectile(player);

		projectiles.push_back(projectile);

		std::cout << "BANG " << projectiles.size() << "\n";
	}

	std::thread shootThread()
	{
		return std::thread([=] {shoot(); });
	}
	*/

	void Update();
	void Draw();
	void DrawProj();
};

#endif;