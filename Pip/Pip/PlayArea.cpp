#include "PlayArea.h"

//Sets play area border sizes
PlayArea::PlayArea()
{
	//(800, 50)
	topBorder = RectangleShape(Vector2f(width, borderSize));
	bottomBorder = RectangleShape(Vector2f(width, borderSize));

	//(50, 600)
	rightBorder = RectangleShape(Vector2f(borderSize, height));
	leftBorder = RectangleShape(Vector2f(borderSize, height));

	SetPositions();
}

PlayArea::~PlayArea()
{
}

FloatRect PlayArea::GetTopBoundingBox()
{
	return topBoundingBox = topBorder.getGlobalBounds();
}

FloatRect PlayArea::GetBottomBoundingBox()
{
	return bottomBoundingBox = bottomBorder.getGlobalBounds();
}

FloatRect PlayArea::GetRightBoundingBox()
{
	return rightBoundingBox = rightBorder.getGlobalBounds();
}

FloatRect PlayArea::GetLeftBoundingBox()
{
	return leftBoundingBox = leftBorder.getGlobalBounds();
}

void PlayArea::SetPositions()
{
	topBorder.setPosition(0, -borderSize);
	bottomBorder.setPosition(0, height);
	rightBorder.setPosition(width, 0);
	leftBorder.setPosition(-borderSize, 0);
}

void PlayArea::Draw(RenderWindow& window)
{
	window.draw(topBorder);
	window.draw(bottomBorder);
	window.draw(rightBorder);
	window.draw(leftBorder);
}
