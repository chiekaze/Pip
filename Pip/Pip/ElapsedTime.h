#ifndef ELAPSEDTIME_H
#define ELAPSEDTIME_H

#include <SFML/Graphics.hpp>
using namespace sf;

class ElapsedTime
{
public:
	ElapsedTime();
	~ElapsedTime();

	int getElapsedTime();

	void Update();
	void Draw(RenderWindow &window);
	void Reset();

private:
	bool mClockReset;

	Font font;
	Text text;
	Clock clock;
	Time playTime;
};

#endif