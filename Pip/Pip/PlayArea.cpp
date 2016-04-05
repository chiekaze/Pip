#include "PlayArea.h"

//Sets play area border sizes
PlayArea::PlayArea()
{
	//(800, 10)
	topBorder = RectangleShape(Vector2f(width, borderSize));
	bottomBorder = RectangleShape(Vector2f(width, borderSize));

	//(10, 600)
	rightBorder = RectangleShape(Vector2f(borderSize, height));
	leftBorder = RectangleShape(Vector2f(borderSize, height));
}

PlayArea::~PlayArea()
{
}

void PlayArea::setPositions()
{
	topBorder.setPosition(0, -borderSize);
	bottomBorder.setPosition(0, height);
	rightBorder.setPosition(width, 0);
	leftBorder.setPosition(-borderSize, 0);
}

FloatRect PlayArea::getTopBoundingBox()
{
	return topBoundingBox = topBorder.getGlobalBounds();
}

FloatRect PlayArea::getBotBoundingBox()
{
	return bottomBoundingBox = bottomBorder.getGlobalBounds();
}

FloatRect PlayArea::getRightBoundingBox()
{
	return rightBoundingBox = rightBorder.getGlobalBounds();
}

FloatRect PlayArea::getLeftBoundingBox()
{
	return leftBoundingBox = leftBorder.getGlobalBounds();
}

void PlayArea::Draw(RenderWindow& window)
{
	window.draw(topBorder);
	window.draw(bottomBorder);
	window.draw(rightBorder);
	window.draw(leftBorder);
}
