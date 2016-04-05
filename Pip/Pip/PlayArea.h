#ifndef PLAY_AREA
#define PLAY_AREA

#include <SFML/Graphics.hpp>

using namespace sf;

class PlayArea
{
public:
	RectangleShape topBorder;
	RectangleShape bottomBorder;
	RectangleShape rightBorder;
	RectangleShape leftBorder;

	FloatRect topBoundingBox;
	FloatRect bottomBoundingBox;
	FloatRect rightBoundingBox;
	FloatRect leftBoundingBox;

	PlayArea();
	~PlayArea();

	void setPositions();

	//Window width and height
	int width = 800;
	int height = 600;

	//Playarea bordersize
	int borderSize = 10;

	FloatRect getTopBoundingBox();
	FloatRect getBotBoundingBox();
	FloatRect getRightBoundingBox();
	FloatRect getLeftBoundingBox();

	void Draw(RenderWindow& window);
};

#endif;