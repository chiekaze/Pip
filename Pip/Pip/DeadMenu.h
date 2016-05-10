#ifndef DEADMENU_H
#define DEADMENU_H

#include <SFML/Graphics.hpp> 
#include <string>
#include "Player.h"
#include "ScoreText.h"
#include "Menu.h"

using namespace sf;

class DeadMenu
{
public:
	DeadMenu();
	~DeadMenu();

	bool isPlaying();
	bool isplaying;

	void Draw(RenderWindow &window);
	void Update();

private:
	Player* player;
	ScoreText* scoretext;
	Menu* menu;

	Font font;

	//Death menu
	Text dead;
	Text score;
	Text restart;
};

#endif