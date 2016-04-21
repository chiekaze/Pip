#include "Player.h"
#include <iostream>

Player::Player()
{
	playerShape = CircleShape(playerSize);
	SetPosition();
}

Player::~Player()
{
	delete playArea;
}

FloatRect Player::GetPlayerBoundingBox()
{
	//Player boundingbox
	return playerBoundingBox = playerShape.getGlobalBounds();
}

Vector2f Player::GetPosition()
{
	return playerShape.getPosition();
}

void Player::SetPosition()
{
	playerShape.setPosition(800 / 2, 600 / 2);
}

void Player::Update()
{
	PlayerInput();
}

void Player::PlayerInput()
{
	playArea = new PlayArea();

	//Player boundingbox
	playerBoundingBox = playerShape.getGlobalBounds();

	//Player speed
	if (Keyboard::isKeyPressed(Keyboard::LControl))
		playerSpeed = playerFocusSpeed;

	else
		playerSpeed = playerNormalSpeed;

	//Movement UP
	if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
	{
		//Collision check
		if (playerBoundingBox.intersects(playArea->GetTopBoundingBox()))
		{
			playerShape.move(0, 0);
		}
		else
			playerShape.move(Vector2f(0, -playerSpeed));
	}

	//Movement DOWN
	if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
	{
		//Collision check
		if (playerBoundingBox.intersects(playArea->GetBottomBoundingBox()))
		{
			playerShape.move(0, 0);
		}
		else
			playerShape.move(Vector2f(0, playerSpeed));
	}

	//Movement RIGHT
	if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
	{
		//Collision check
		if (playerBoundingBox.intersects(playArea->GetRightBoundingBox()))
		{
			playerShape.move(0, 0);
		}
		else
			playerShape.move(Vector2f(playerSpeed, 0));
	}

	//Movement LEFT
	if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
	{
		//Collision check
		if (playerBoundingBox.intersects(playArea->GetLeftBoundingBox()))
		{
			playerShape.move(0, 0);
		}
		else
			playerShape.move(Vector2f(-playerSpeed, 0));
	}
}

void Player::Draw(RenderWindow& window)
{
	window.draw(playerShape);
}