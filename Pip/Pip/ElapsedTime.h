#ifndef ELAPSEDTIME_H
#define ELAPSEDTIME_H

#include "Menu.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class ElapsedTime
{
public:
	ElapsedTime();
	~ElapsedTime();

	Font font;
	Text text;
	Clock clock;
	Time playTime;

	int getElapsedTime();

	void Update();
	void Draw(RenderWindow &window);

private:
	bool mClockReset;
	Menu* menu;
};

#endif