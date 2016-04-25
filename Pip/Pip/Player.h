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
	bool IsDead();
	void Update();
	void PlayerInput();
	void Draw(RenderWindow& window);

	Font font;
	Text text;

private:
	PlayArea* playArea;

	Texture playerText;
	Sprite playerSprite;

	FloatRect playerBoundingBox;
	
	int playerSpeed;
	int playerNormalSpeed = 5;
	int playerFocusSpeed = 2;
	int playerHP = 100;
};

#endif;