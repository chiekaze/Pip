#include "SoundManager.h"

SoundManager::SoundManager()
{
	mute = false;

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
	if (!mute || MuteOff())
	{
		enemydeath.setBuffer(enemyDeath);
		enemydeath.play();
	}
}

void SoundManager::PlayerDeathSound()
{
	if (!mute || MuteOff())
	{
		playerdeath.setBuffer(playerDeath);
		playerdeath.play();
	}
}

void SoundManager::ProjectileSound()
{
	if (!mute || MuteOff())
	{
		projectilesound.setBuffer(projectileSound);
		projectilesound.play();
	}
}

void SoundManager::PlayerHurt()
{
	if (!mute || MuteOff())
	{
		playerhurt.setBuffer(playerHurt);
		playerhurt.play();
	}
}

void SoundManager::HealthPickupSound()
{
	if (!mute || MuteOff())
	{
		healthpickup.setBuffer(healthPickUp);
		healthpickup.play();
	}
}

void SoundManager::GameOver()
{
	if (!mute || MuteOff())
	{
		gameover.setBuffer(gameOver);
		gameover.play();
	}
}

void SoundManager::AsteroidExplosion()
{
	if (!mute || MuteOff())
	{
		asteroidexplosion.setBuffer(asteroidExplosion);
		asteroidexplosion.play();
	}
}

void SoundManager::PlayerFocusSound()
{
	if (!mute || MuteOff())
	{
		playerfocussound.setBuffer(playerFocusSound);
		playerfocussound.play();
	}
}

bool SoundManager::MuteOn()
{
	if (!mute || MuteOff())
	{
		if (event.type == Event::KeyPressed && event.key.code == Keyboard::LShift)
		{
			std::cout << "sound off!\n";
			return true;
		}
	}
	else
		return false;
}

bool SoundManager::MuteOff()
{
	if (MuteOn())
	{
		if (event.type == Event::KeyPressed && event.key.code == Keyboard::LShift)
		{
			std::cout << "sound on!\n";
			return true;
		}
		else
			return false;
	}
}

void SoundManager::Update()
{
	MuteOn();
	MuteOff();
}