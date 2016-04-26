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
	void PlayerHurt();

private:
	SoundBuffer enemyDeath;
	SoundBuffer projectileSound;
	SoundBuffer playerDeath;
	SoundBuffer playerHurt;
	Sound sound;
};

#endif