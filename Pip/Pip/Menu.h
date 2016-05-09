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
	void Draw(RenderWindow &window);
	void Update();

	bool isPlaying;

private:
	Font font;
	
	Text title; 
	Text start;
	Text quit;
	Text controls;
	Text move;
	Text shoot;
	Text focus;
};

#endif;