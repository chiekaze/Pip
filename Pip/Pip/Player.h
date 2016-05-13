#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "PlayArea.h"

using namespace sf;

class Player
{
public:
	Player();
	~Player();

	Vector2f GetPosition();

	FloatRect GetPlayerBoundingBox();
	void SetPosition();
	int GetPlayerHP();
	void TakeDamage(int damage);
	void TakeHealth(int health);
	bool IsDead();
	void Update();
	void PlayerInput();
	void SetPlayerHP(int hp);
	void Draw(RenderWindow& window);

	bool PlayerFocus();
	float GetPlayerFocusFactor();

private:
	PlayArea* playArea;

	Font font;
	Text text;
	Text focus;

	Texture playerText;
	Texture playerHurtText;
	Texture playerPickupText;
	
	Texture focusBGText;
	Sprite focusBGSprite;

	Sprite playerSprite;

	FloatRect playerBoundingBox;
	
	float playerSpeed;
	float playerNormalSpeed;
	float playerFocusFactor;
	int playerHP;
	int playerFullHP;
};

#endif;