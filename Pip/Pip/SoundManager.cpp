#include "SoundManager.h"

SoundManager::SoundManager()
{

}

SoundManager::~SoundManager()
{

}

void SoundManager::EnemyDeathSound()
{
	buffer.loadFromFile("sounds/explosion1.wav");
	sound.setBuffer(buffer);
	sound.play();
	std::cout << "Sound played!";
}

void SoundManager::PlayerDeathSound()
{
	buffer.loadFromFile("sounds/explosion1.wav");
	sound.setBuffer(buffer);
	sound.play();
}

void SoundManager::ProjectileSound()
{
	buffer.loadFromFile("sounds/explosion1.wav");
	sound.setBuffer(buffer);
	sound.play();
}