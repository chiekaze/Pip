#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp> 
using namespace sf;

class Menu
{
public:
	Menu();
	~Menu();

	Font font;
	Text text; 
		
	Event event; 

	bool IsPlaying();
	void Draw(RenderWindow &window);
};

#endif;