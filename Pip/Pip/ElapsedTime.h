#ifndef ELAPSEDTIME_H
#define ELAPSEDTIME_H

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
	Time playTime = clock.getElapsedTime();

	int getElapsedTime();

	void Update();
	void Draw(RenderWindow &window);
};

#endif