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
#include "ElapsedTime.h"
#include "SoundManager.h"
#include "HealthPack.h"
//#include "Menu.h"

using namespace sf;

class Game
{
public:
	Game();
	~Game();

	void UpdateSpawnTimer();

	void Update();
	void Draw();

	Text text;
	Font font;

private:
	RenderWindow* window;
	Player* player;
	PlayArea* playArea;
	Background* bg;
	Starfield* sf;
	ScoreText* scoreTxt;
	ElapsedTime* elapsedTime;
	SoundManager* soundManager;
	//Menu* menu;

	Projectile* projectile;
	std::vector<Projectile*> projectiles;

	Enemy* enemy;
	std::vector<Enemy*> enemies;

	EnemyProjectile* enemyprojectile;
	std::vector<EnemyProjectile*> enemyprojectiles;

	HealthPack* healthpack;
	std::vector<HealthPack*> healthpacks;
	
	Event event;
	Event event1;
	Event event2;

	float projectileTimer;
	float healthTimer;
	float spawnTimer;

	float spawnTimerValue;
	int lastSpawnTimerUpdate;
	int spawnRateTime;

	float healthTimerValue;
	int lastHealthTimerUpdate;
	int healthTime;

	int healthTop;
	int healthBottom;

	int windowWidth;
	int windowHeight;

	int score;

	bool isPlaying;
};

#endif;