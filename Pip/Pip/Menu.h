#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp> 
#include <fstream>
#include <string>
#include "Player.h"
#include "ElapsedTime.h"
#include "ScoreText.h"

using namespace sf;
using namespace std;

class Menu
{
public:
	Menu(Player*,ScoreText*);
	~Menu();

	bool IsPlaying();
	bool IsNotPlaying();
	void StopPlaying();
	void StartPlaying();

	void Draw(RenderWindow &window);
	void DrawDeadMenu(RenderWindow &window);
	void Update();
	void UpdateDeadMenu();

private:

	ElapsedTime* elapsedTime;
	Player* mPlayer;
	ScoreText* scrTxt;

	Font font;
	
	//Start menu
	Text title; 
	Text start;
	Text quit;
	Text controls;
	Text move;
	Text shoot;
	Text focus;
	
	//End menu
	Text dead;
	Text restart;
	Text scoreTxt;
	Text quit2;

	bool isPlaying;
	int finalScore;
};

#endif;