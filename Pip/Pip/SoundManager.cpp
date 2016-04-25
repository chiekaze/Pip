#include "SoundManager.h"

SoundManager::SoundManager()
{

}

SoundManager::~SoundManager()
{

}

void SoundManager::EnemyDeathSound()
{
	if (!enemyDeath.loadFromFile("sounds/explosion1.wav"))
	{
		std::cout << "Sound not played :(\n";
	}
	enemyDeath.loadFromFile("sounds/explosion1.wav");
	sound.setBuffer(enemyDeath);
	sound.play();
}

void SoundManager::PlayerDeathSound()
{
	/*buffer.loadFromFile("sounds/explosion1.wav");
	sound.setBuffer(buffer);
	sound.play();*/
}

void SoundManager::ProjectileSound()
{
	/*buffer.loadFromFile("sounds/explosion1.wav");
	sound.setBuffer(buffer);
	sound.play();*/
}