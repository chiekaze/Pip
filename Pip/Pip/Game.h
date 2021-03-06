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
#include "Menu.h"
#include "Asteroid.h"

using namespace sf;

class Game
{
public:
	Game();
	~Game();

	void UpdateSpawnTimer();

	void Update();
	void Draw();

private:
	RenderWindow* window;
	Player* player;
	PlayArea* playArea;
	Background* bg;
	Starfield* sf;
	ScoreText* scoreTxt;
	ElapsedTime* elapsedTime;
	SoundManager* soundManager;
	Menu* menu;

	Asteroid* asteroid;
	std::vector<Asteroid*> asteroids;

	Projectile* projectile;
	std::vector<Projectile*> projectiles;

	Enemy* enemy;
	std::vector<Enemy*> enemies;

	EnemyProjectile* enemyprojectile;
	std::vector<EnemyProjectile*> enemyprojectiles;

	HealthPack* healthpack;
	std::vector<HealthPack*> healthpacks;
	
	Event event;

	float projectileTimer;
	float healthTimer;
	float spawnTimer;
	float asteroidTimer;

	float spawnTimerFocus;
	float spawnTimerNormal;
	float spawnTimerValue;
	int lastSpawnTimerUpdate;
	int spawnRateTime;

	float asteroidTimerFocus;
	float asteroidTimerNormal;
	float asteroidTimerValue;
	int lastAsteroidUpdate;
	int asteroidTime;

	float healthTimerValue;
	float healthTimerAddition;
	int lastHealthTimerUpdate;
	int healthTime;

	int healthTop;
	int healthBottom;

	int windowWidth;
	int windowHeight;

	int score;
	bool mute;

	bool isPlaying;
	void Mute();

	Font font;
	Text text;
};

#endif;