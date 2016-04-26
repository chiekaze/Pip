#include "SoundManager.h"

SoundManager::SoundManager()
{
	enemyDeath.loadFromFile("sounds/explosion1.wav");
	playerDeath.loadFromFile("sounds/playerdeath.wav");
	playerHurt.loadFromFile("sounds/playerhurt.wav");
	healthPickUp.loadFromFile("sounds/health.wav");
	projectileSound.loadFromFile("sounds/playershoot.wav");
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
	sound.setBuffer(projectileSound);
	sound.play();
}

void SoundManager::PlayerHurt()
{
	sound.setBuffer(playerHurt);
	sound.play();
}

void SoundManager::HealthPickupSound()
{
	sound.setBuffer(healthPickUp);
	sound.play();
}