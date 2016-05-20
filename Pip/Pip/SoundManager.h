#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;

class SoundManager
{
public:
	SoundManager();
	~SoundManager();

	void EnemyDeathSound();
	void ProjectileSound();
	void PlayerDeathSound();
	void HealthPickupSound();
	void PlayerHurt();
	void GameOver();
	void AsteroidExplosion();
	void PlayerFocusSound();

private:
	SoundBuffer enemyDeath;
	SoundBuffer projectileSound;
	SoundBuffer playerDeath;
	SoundBuffer playerHurt;
	SoundBuffer healthPickUp;
	SoundBuffer gameOver;
	SoundBuffer asteroidExplosion;
	SoundBuffer playerFocusSound;

	Sound enemydeath;
	Sound projectilesound;
	Sound playerdeath;
	Sound playerhurt;
	Sound healthpickup;
	Sound gameover;
	Sound asteroidexplosion;
	Sound playerfocussound;
};

#endif