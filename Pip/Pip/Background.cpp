//#include "Background.h"
//
////Background::Background()
////{
////	bgTexture.loadFromFile("sprites/background.png");
////	bgTexture.setSmooth(false);
////	bgTexture.setRepeated(true);
////	bgSprite.setTexture(bgTexture);
////	bg.y
////
////	bgY = bgShape.getPosition().y;
////	bgSize.x = 800;
////	bgSize.y = 600;
////	bgShape.setTexture(&bgTexture);
////	bgShape.setSize(bgSize);
////
////	bg2Texture.loadFromFile("sprites/background.png");
////	bg2Texture.setSmooth(false);
////	bg2Texture.setRepeated(true);
////
////
////	bgY = bgShape.getPosition().y;
////	bgSize.x = 800;
////	bgSize.y = 600;
////	bgShape.setTexture(&bgTexture);
////	bgShape.setSize(bgSize);
////}
////
////Background::~Background()
////{
////}
////
////void Background::Update()
////{
////	if (bgY < 600)
////	{
////		bgY += bgSpeed;
////	}
////
////	else
////	{
////		bgY = bgShape.getPosition().y;
////	}
////	
////	bgShape.setPosition(0, bgY);
////	
////	bgShape.move(Vector2f(0, bgSpeed));
////}
////
////void Background::Draw(RenderWindow& window)
////{
////	window.draw(bgShape);
////}
//
//Background::Background()
//{
//	bgSpeed = 0.3;
//
//	bg1Tex.loadFromFile("graphics//background.jpg");
//	bg1Tex.setSmooth(false);
//	bg1Sprite.setTexture(bg1Tex);
//	bg1Y = bg1Sprite.getPosition().y;
//
//	bg2Tex.loadFromFile("graphics//background.jpg");
//	bg2Tex.setSmooth(false);
//	bg2Sprite.setTexture(bg2Tex);
//	bg2Sprite.setPosition(0, 601);
//	bg2Y = bg2Sprite.getPosition ().y;
//}
//
//
//void Background::Update()
//{
//	windowbg1diff = bg1Y - 600;
//
//	if (bg1Y >= 600)
//	{
//		bg1Y = -590;
//	}
//	else
//	{
//		bg1Y += bgSpeed;
//	}
//
//	if (bg2Y >= 600)
//	{
//		bg2Y = -600;
//	}
//	else if (bg2Y < bg1Y)
//	{
//		bg2Y = windowbg1diff + 5;
//	}
//	else
//	{
//		bg2Y += bgSpeed;
//	}
//
//	bg1Sprite.setPosition(0, bg1Y);
//	bg2Sprite.setPosition(0, bg2Y);
//}
//void Background::Draw(sf::RenderWindow &window)
//{
//	window.draw(bg1Sprite);
//	window.draw(bg2Sprite);
//}