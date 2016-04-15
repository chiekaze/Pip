#include "Player.h"

Player::Player()
{
	playerShape = CircleShape(playerSize);
	
	playArea = new PlayArea();
	playArea->setPositions();
	
	setPosition();
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

void Player::Update()
{
	PlayerInput();
}

void Player::PlayerInput()
{
	//Player boundingbox
	FloatRect playerBoundingBox = playerShape.getGlobalBounds();

	//Player speed
	if (Keyboard::isKeyPressed(Keyboard::LControl))
		playerSpeed = playerFocusSpeed;

	else
		playerSpeed = playerNormalSpeed;

	//Movement UP
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		//Collision check
		if (playerBoundingBox.intersects(playArea->getTopBoundingBox()))
		{
			playerShape.move(0, 0);
		}
		else
			playerShape.move(Vector2f(0, -playerSpeed));
	}

	//Movement DOWN
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		//Collision check
		if (playerBoundingBox.intersects(playArea->getBotBoundingBox()))
		{
			playerShape.move(0, 0);
		}
		else
			playerShape.move(Vector2f(0, playerSpeed));
	}

	//Movement RIGHT
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		//Collision check
		if (playerBoundingBox.intersects(playArea->getRightBoundingBox()))
		{
			playerShape.move(0, 0);
		}
		else
			playerShape.move(Vector2f(playerSpeed, 0));
	}

	//Movement LEFT
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		//Collision check
		if (playerBoundingBox.intersects(playArea->getLeftBoundingBox()))
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