#include "PlayArea.h"

//Sets play area border sizes
PlayArea::PlayArea()
{
	width = 800;
	height = 600;
	borderSize = 50;
	enemyBorderWidth = 1800;

	//(800, 50)
	topBorder = RectangleShape(Vector2f(width, borderSize));
	bottomBorder = RectangleShape(Vector2f(width, borderSize));

	//(50, 600)
	rightBorder = RectangleShape(Vector2f(borderSize, height));
	leftBorder = RectangleShape(Vector2f(borderSize, height));

	//(1800, 50)
	enemyBorder = RectangleShape(Vector2f(enemyBorderWidth, borderSize));

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

FloatRect PlayArea::GetEnemyBorderBoundingBox()
{
	return enemyBorderBoundingBox = enemyBorder.getGlobalBounds();
}

void PlayArea::SetPositions()
{
	topBorder.setPosition(0, -borderSize);
	bottomBorder.setPosition(0, height);
	rightBorder.setPosition(width, 0);
	leftBorder.setPosition(-borderSize, 0);
	enemyBorder.setPosition(0, height + 100);
}

void PlayArea::Draw(RenderWindow& window)
{
	window.draw(topBorder);
	window.draw(bottomBorder);
	window.draw(rightBorder);
	window.draw(leftBorder);
	window.draw(enemyBorder);
}
