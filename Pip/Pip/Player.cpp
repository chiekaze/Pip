#include "Player.h"
#include <iostream>
#include <thread>

Player::Player()
{
	playerShape = CircleShape(playerSize);
	playArea = new PlayArea();

	playArea->setPositions();
}

Player::~Player()
{
}

void Player::setPosition()
{
	playerShape.setPosition(800 / 2, 600 / 2);
}

Vector2f Player::getPosition()
{
	return playerShape.getPosition();
}

void Player::shootProjectile()
{
	Projectile projectile;
	projectile.projectileShape.setPosition(playerShape.getPosition());

	//This is supposed to delay the shots, and it sort of does
	Time delayTime = milliseconds(100);

	//Checking if it's working
	if (projectile.projectileShape.getPosition() == playerShape.getPosition())
	{
		std::cout << &Projectile::getProjectilePosition << ", this means the projectile spawns where the player is. ";
	}
	sleep(delayTime);
}

void Player::Update(Clock& clock)
{
	//Player boundingbox
	FloatRect playerBoundingBox = playerShape.getGlobalBounds();

	if (Keyboard::isKeyPressed(Keyboard::LControl))
		playerSpeed = playerFocusSpeed;

	else
		playerSpeed = playerNormalSpeed;

	//Move up
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		//Collision check here
		if (playerBoundingBox.intersects(playArea->getTopBoundingBox()))
		{
			playerShape.move(0, 0);
		}
		else
			playerShape.move(Vector2f(0, -playerSpeed * clock.getElapsedTime().asSeconds()));
	}

	//Move down
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		//Collision check here
		if (playerBoundingBox.intersects(playArea->getBotBoundingBox()))
		{
			playerShape.move(0, 0);
		}
		else
			playerShape.move(Vector2f(0, playerSpeed * clock.getElapsedTime().asSeconds()));
	}

	//Move right
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		//Collision check here
		if (playerBoundingBox.intersects(playArea->getRightBoundingBox()))
		{
			playerShape.move(0, 0);
		}
		else
			playerShape.move(Vector2f(playerSpeed * clock.getElapsedTime().asSeconds(), 0));
	}

	//Move left
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		//Collision check here
		if (playerBoundingBox.intersects(playArea->getLeftBoundingBox()))
		{
			playerShape.move(0, 0);
		}
		else
			playerShape.move(Vector2f(-playerSpeed * clock.getElapsedTime().asSeconds(), 0));
	}

	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		//std::thread projectile (&Player::shootProjectile, this);
		//this->shootProjectile();
		shootProjectile();
	}
	/*
	//This is supposed to check if the enemy is there but apparently it crashes the game
	if (playerBoundingBox.intersects(enemy->getEnemyBox()))
	{
		std::cout << "The enemy is nearby! ";
	}
	*/
}

void Player::Draw(RenderWindow& window)
{
	window.draw(playerShape);
}