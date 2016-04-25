#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "Player.h"
#include "PlayArea.h"
#include "Projectile.h"
#include "Enemy.h"
#include "BackGround.h"
#include "StarField.h"
#include "EnemyProjectile.h"
#include "ScoreText.h"

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
	ScoreText* scoreTxt;

	Projectile* projectile;
	std::vector<Projectile*> projectiles;

	Enemy* enemy;
	std::vector<Enemy*> enemies;

	EnemyProjectile* enemyprojectile;
	std::vector<EnemyProjectile*> enemyprojectiles;
	
	Event event;
	Clock clock;
	Time elapsed = clock.getElapsedTime();

	int windowWidth = 800;
	int windowHeight = 600;

	int score = 0;
};

#endif;