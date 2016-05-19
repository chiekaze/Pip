#ifndef PLAY_AREA
#define PLAY_AREA

#include <SFML/Graphics.hpp>

using namespace sf;

class PlayArea
{
public:
	PlayArea();
	~PlayArea();

	FloatRect GetTopBoundingBox();
	FloatRect GetBottomBoundingBox();
	FloatRect GetRightBoundingBox();
	FloatRect GetLeftBoundingBox();
	FloatRect GetEnemyBorderBoundingBox();

	void SetPositions();
	void Draw(RenderWindow& window);

private:
	RectangleShape topBorder;
	RectangleShape bottomBorder;
	RectangleShape rightBorder;
	RectangleShape leftBorder;
	RectangleShape enemyBorder;

	FloatRect topBoundingBox;
	FloatRect bottomBoundingBox;
	FloatRect rightBoundingBox;
	FloatRect leftBoundingBox;
	FloatRect enemyBorderBoundingBox;

	//Window width and height
	int width;
	int height;
	int enemyBorderWidth;

	//Playarea bordersize
	int borderSize;
};

#endif;