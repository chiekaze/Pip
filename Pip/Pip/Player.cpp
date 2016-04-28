#include "Player.h"
#include <iostream>

Player::Player()
{
	playerText.loadFromFile("sprites/player_ship.png");
	playerText.setSmooth(false);

	playerHurtText.loadFromFile("sprites/player_ship_damage.png");
	playerHurtText.setSmooth(false);
	
	playerSprite.setTexture(playerText);
	playerSprite.setTextureRect(IntRect(0, 0, 32, 32));
	playerSprite.setScale(2, 2);
	playerSprite.setOrigin(15, 5);

	font.loadFromFile("fonts/Minecraft.ttf"); 
	text.setString("HEALTH: " + std::to_string(playerHP)); 
	text.setFont(font); text.setCharacterSize(22);
	text.setPosition(Vector2f(5, 30));

	SetPosition();
}

Player::~Player()
{
	delete playArea;
}

FloatRect Player::GetPlayerBoundingBox()
{
	//Player boundingbox
	return playerBoundingBox = playerSprite.getGlobalBounds();
}

Vector2f Player::GetPosition()
{
	return playerSprite.getPosition();
}

void Player::SetPosition()
{
	playerSprite.setPosition(800 / 2, 600 / 2);
}

void Player::Update()
{
	playerSprite.setTexture(playerText);
	PlayerInput();
}

int Player::GetPlayerHP()
{
	return playerHP;
}

void Player::TakeDamage(int damage)
{
	playerSprite.setTexture(playerHurtText);
	text.setString("HEALTH: " + std::to_string(playerHP -= damage));
}

void Player::TakeHealth(int health)
{
	if (playerHP <= 100 - health)
	{
		text.setString("HEALTH: " + std::to_string(playerHP += health));
	}

	//To make sure that the HP won't go over 100
	else if (100 - health < playerHP < 100)
	{
		std::cout << "Too much health motherfucker!\n";
		text.setString("HEALTH: " + std::to_string(playerHP = 100));
	}
}

bool Player::IsDead()
{
	if (playerHP <= 0)
		return true;

	else
		return false;
}

void Player::PlayerInput()
{
	playArea = new PlayArea();

	//Player boundingbox
	playerBoundingBox = playerSprite.getGlobalBounds();

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
			playerSprite.move(0, 0);
		}
		else
			playerSprite.move(Vector2f(0, -playerSpeed));
	}

	//Movement DOWN
	if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
	{
		//Collision check
		if (playerBoundingBox.intersects(playArea->GetBottomBoundingBox()))
		{
			playerSprite.move(0, 0);
		}
		else
			playerSprite.move(Vector2f(0, playerSpeed));
	}

	//Movement RIGHT
	if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
	{
		//Collision check
		if (playerBoundingBox.intersects(playArea->GetRightBoundingBox()))
		{
			playerSprite.move(0, 0);
		}
		else
			playerSprite.move(Vector2f(playerSpeed, 0));
	}

	//Movement LEFT
	if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
	{
		//Collision check
		if (playerBoundingBox.intersects(playArea->GetLeftBoundingBox()))
		{
			playerSprite.move(0, 0);
		}
		else
			playerSprite.move(Vector2f(-playerSpeed, 0));
	}
}

void Player::Draw(RenderWindow& window)
{
	window.draw(playerSprite);
	window.draw(text);
}