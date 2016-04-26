#include "SoundManager.h"

SoundManager::SoundManager()
{
	enemyDeath.loadFromFile("sounds/explosion1.wav");
	playerDeath.loadFromFile("sounds/playerdeath.wav");
	playerHurt.loadFromFile("sounds/playerhurt.wav");
}

SoundManager::~SoundManager()
{

}

void SoundManager::EnemyDeathSound()
{
	sound.setBuffer(enemyDeath);
	sound.play();
}

void SoundManager::PlayerDeathSound()
{
	sound.setBuffer(playerDeath);
	sound.play();
}

void SoundManager::ProjectileSound()
{
	/*buffer.loadFromFile("sounds/explosion1.wav");
	sound.setBuffer(buffer);
	sound.play();*/
}

void SoundManager::PlayerHurt()
{
	sound.setBuffer(playerHurt);
	sound.play();
}