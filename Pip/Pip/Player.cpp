#include "Player.h"
#include <iostream>

Player::Player()
{
	playerFullHP = 100;
	playerHP = playerFullHP;

	playerText.loadFromFile("sprites/player_ship.png");
	playerText.setSmooth(false);

	playerHurtText.loadFromFile("sprites/player_ship_damage.png");
	playerHurtText.setSmooth(false);

	playerPickupText.loadFromFile("sprites/player_ship_pickup.png");
	playerPickupText.setSmooth(false);

	focusBGText.loadFromFile("sprites/focus.png");
	focusBGText.setSmooth(false);

	focusBGSprite.setTexture(focusBGText);
	
	playerSprite.setTexture(playerText);
	playerSprite.setTextureRect(IntRect(0, 0, 32, 32));
	playerSprite.setScale(2, 2);
	playerSprite.setOrigin(15, 5);

	font.loadFromFile("fonts/Minecraft.ttf"); 
	text.setString("HEALTH: " + std::to_string(playerHP)); 
	text.setFont(font); text.setCharacterSize(22);
	text.setPosition(Vector2f(5, 30));

	focus.setString("FOCUS ENABLED!");
	focus.setFont(font); focus.setCharacterSize(20);
	focus.setPosition(Vector2f(5, 570));

	playerNormalSpeed = 5;
	playerFocusFactor = 0.4;

	SetPosition();
}

Player::~Player()
{
	delete playArea;
}

FloatRect Player::GetPlayerBoundingBox()
{
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

void Player::SetPlayerHP(int hp)
{
	playerHP = hp;
}

void Player::Update()
{
	playerSprite.setTexture(playerText);
	PlayerInput();
	text.setString("HEALTH: " + std::to_string(GetPlayerHP()));
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
	playerSprite.setTexture(playerPickupText);

	if (playerHP <= playerFullHP - health)
	{
		text.setString("HEALTH: " + std::to_string(playerHP += health));
	}

	//To make sure that the HP won't go over full HP
	else if (playerFullHP - health < playerHP < playerFullHP)
	{
		text.setString("HEALTH: " + std::to_string(playerHP = playerFullHP));
	}
}

bool Player::IsDead()
{
	if (playerHP <= 0)
		return true;

	else
		return false;
}

bool Player::IsAlive()
{
	if (IsDead())
		return false;
	else
		return true;
}

bool Player::PlayerFocus()
{
	if (Keyboard::isKeyPressed(Keyboard::LControl))
	{
		return true;
	}
	else
		return false;
}

float Player::GetPlayerFocusFactor()
{
	return playerFocusFactor;
}

void Player::PlayerInput()
{
	playArea = new PlayArea();

	//Player boundingbox
	playerBoundingBox = playerSprite.getGlobalBounds();

	//Player speed
	if (PlayerFocus())
		playerSpeed = playerNormalSpeed * playerFocusFactor;
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

	if (PlayerFocus())
	{
		window.draw(focus);
		window.draw(focusBGSprite);
	}
}