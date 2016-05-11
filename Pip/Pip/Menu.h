#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp> 

using namespace sf;

class Menu
{
public:
	Menu();
	~Menu();

	bool IsPlaying();
	bool isNotPlaying();
	void stopPlaying();
	void startPlaying();

	void Draw(RenderWindow &window);
	void DrawEndMenu(RenderWindow &window);
	void Update();

	bool isPlaying;

private:

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
	Text score;
};

#endif;