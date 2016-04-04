#include "Player.h"

Player::Player()
{
	playerShape = CircleShape(playerSize);
}

Player::~Player()
{
}

void Player::Update(Clock& clock)
{
	if (Keyboard::isKeyPressed(Keyboard::Z))
		playerSpeed = playerFocusSpeed;
		
	else
		playerSpeed = playerNormalSpeed;

	//Move up
	if (Keyboard::isKeyPressed(Keyboard::Up))
		playerShape.move(Vector2f(0, -playerSpeed * clock.getElapsedTime().asSeconds()));

	//Move down
	if (Keyboard::isKeyPressed(Keyboard::Down))
		playerShape.move(Vector2f(0, playerSpeed * clock.getElapsedTime().asSeconds()));

	//Move right
	if (Keyboard::isKeyPressed(Keyboard::Right))
		playerShape.move(Vector2f(playerSpeed * clock.getElapsedTime().asSeconds(), 0));

	//Move left
	if (Keyboard::isKeyPressed(Keyboard::Left))
		playerShape.move(Vector2f(-playerSpeed * clock.getElapsedTime().asSeconds(), 0));
}

void Player::Draw(RenderWindow& window)
{
	window.draw(playerShape);
}