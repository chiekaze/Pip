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

private:
	PlayArea* playArea;

	Texture playerText;
	RectangleShape playerShape;
	Sprite playerSprite;
	Vector2f playerSize;

	FloatRect playerBoundingBox;
	
	//int playerSize = 5;
	int playerSpeed;
	int playerNormalSpeed = 5;
	int playerFocusSpeed = 2;
	int playerHP = 100;
};

#endif;