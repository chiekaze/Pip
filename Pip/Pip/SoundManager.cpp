#include "SoundManager.h"

SoundManager::SoundManager()
{
	enemyDeath.loadFromFile("sounds/explosion1.wav");
	playerDeath.loadFromFile("sounds/playerdeath.wav");
	playerHurt.loadFromFile("sounds/playerhurt.wav");
	healthPickUp.loadFromFile("sounds/health.wav");
	projectileSound.loadFromFile("sounds/playershoot.wav");
	gameOver.loadFromFile("sounds/gameover.wav");
	asteroidExplosion.loadFromFile("sounds/explosion2.wav");
	playerFocusSound.loadFromFile("sounds/warp.wav");
}

SoundManager::~SoundManager()
{
}

void SoundManager::EnemyDeathSound()
{
		enemydeath.setBuffer(enemyDeath);
		enemydeath.play();
}

void SoundManager::PlayerDeathSound()
{
		playerdeath.setBuffer(playerDeath);
		playerdeath.play();
}

void SoundManager::ProjectileSound()
{
		projectilesound.setBuffer(projectileSound);
		projectilesound.play();
}

void SoundManager::PlayerHurt()
{
		playerhurt.setBuffer(playerHurt);
		playerhurt.play();
}

void SoundManager::HealthPickupSound()
{
		healthpickup.setBuffer(healthPickUp);
		healthpickup.play();
}

void SoundManager::GameOver()
{
		gameover.setBuffer(gameOver);
		gameover.play();
}

void SoundManager::AsteroidExplosion()
{
		asteroidexplosion.setBuffer(asteroidExplosion);
		asteroidexplosion.play();
}

void SoundManager::PlayerFocusSound()
{
		playerfocussound.setBuffer(playerFocusSound);
		playerfocussound.play();
}