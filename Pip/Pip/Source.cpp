#include "Game.h"

int main()
{
	Game game;
	game.Update();
	return 0;
}

//using namespace sf;
//
//int main()
//{
//	int width = 800;
//	int height = 600;
//	
//	float playerSpeed;
//	float playerNormalSpeed = 0.05;
//	float playerFocusSpeed = 0.025;
//	
//	int playerSize = 5;
//	int projectileSize = 3;
//	int playerHP = 100;
//
//	//Enemy enemy1(10, 0.025, 50);
//	int enemysize = 10;
//	int enemyHP = 50;
//	
//	float projectileSpeed = 0.05;
//
//	//Playarea border sizes
//	int borderSize = 10;
//
//	RenderWindow window(VideoMode(width, height), "Pip");
//
//	//Playarea
//	RectangleShape top, bottom, right, left;
//
//	top.setPosition(0, -borderSize);
//	top.setSize(Vector2f(width, borderSize));
//	top.setFillColor(Color::White);
//
//	bottom.setPosition(0, height);
//	bottom.setSize(Vector2f(width, borderSize));
//	bottom.setFillColor(Color::White);
//
//	right.setPosition(width, 0);
//	right.setSize(Vector2f(borderSize, height));
//	right.setFillColor(Color::White);
//
//	left.setPosition(-borderSize, 0);
//	left.setSize(Vector2f(borderSize, height));
//	left.setFillColor(Color::White);
//	
//	//Player
//	CircleShape player(playerSize);
//	
//	player.setFillColor(Color::White);
//	player.setPosition(width / 2, height / 2);
//
//	/*
//	//Enemy
//	CircleShape enemy1();
//	
//	enemy1.setFillColor(Color::Red);
//	enemy1.setPosition(width / 2, height - 500);
//	*/
//
//	CircleShape enemy(enemysize);
//	enemy.setFillColor(Color::Red);
//	enemy.setPosition(width / 2, height - 500);
//	
//	//Projectile
//	CircleShape projectile(projectileSize);
//	projectile.setFillColor(Color::Yellow);
//	projectile.setPosition(player.getPosition());
//
//	while (window.isOpen())
//	{
//		window.clear(Color::Black);
//		
//		window.draw(player);
//		window.draw(top);
//		window.draw(bottom);
//		window.draw(right);
//		window.draw(left);
//		//window.draw(enemy1);
//		window.draw(enemy);
//		window.draw(projectile);
//		window.display();
//
//		FloatRect playerBoundingBox = player.getGlobalBounds();
//		FloatRect leftBoundingBox = left.getGlobalBounds(); 
//		FloatRect rightBoundingBox = right.getGlobalBounds();
//		FloatRect topBoundingBox = top.getGlobalBounds();
//		FloatRect bottomBoundingBox = bottom.getGlobalBounds();
//		FloatRect enemyBoundingBox = enemy.getGlobalBounds();
//		FloatRect projectileBoundingBox = projectile.getGlobalBounds();
//
//		Event event;
//		while (window.pollEvent(event))
//		{
//			if ((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
//				window.close();
//		}
//
//		//Movement
//		if (Keyboard::isKeyPressed(Keyboard::Z))
//			playerSpeed = playerFocusSpeed;
//		else
//			playerSpeed = playerNormalSpeed;
//
//		if (Keyboard::isKeyPressed(Keyboard::Left))
//		{
//			//Collision checks
//
//			if (playerBoundingBox.intersects(leftBoundingBox))
//			{
//				player.move(0, 0);
//			}
//
//			else
//				player.move(-playerSpeed, 0);
//		}
//
//		if (Keyboard::isKeyPressed(Keyboard::Right))
//		{
//			//Collision checks
//
//			if (playerBoundingBox.intersects(rightBoundingBox))
//			{
//				player.move(0, 0);
//			}
//
//			else
//				player.move(playerSpeed, 0);
//		}
//
//		if (Keyboard::isKeyPressed(Keyboard::Up))
//		{
//			//Collision checks
//
//			if (playerBoundingBox.intersects(topBoundingBox))
//			{
//				player.move(0, 0);
//			}
//
//			else
//				player.move(0, -playerSpeed);
//		}
//
//		if (Keyboard::isKeyPressed(Keyboard::Down))
//		{
//			//Collision checks
//
//			if (playerBoundingBox.intersects(bottomBoundingBox))
//			{
//				player.move(0, 0);
//			}
//
//			else
//				player.move(0, playerSpeed);
//		}
//
//		if (playerBoundingBox.intersects(enemyBoundingBox))
//		{
//			std::cout << "You're fucking dead m8! ";
//			playerHP--;
//		}
//
//		if (Keyboard::isKeyPressed(Keyboard::Space))
//		{
//			projectile.move(0, -projectileSpeed);
//		}
//
//		if (projectileBoundingBox.intersects(enemyBoundingBox))
//		{
//			std::cout << "MAKE AMERICA GREAT AGAIN! ";
//			enemyHP--;
//		}
//
//		if (enemyHP == 0)
//		{
//			std::cout << "\nYou won the game!";
//			system("PAUSE");
//			return 0;
//		}
//
//		if (playerHP == 0)
//		{
//			return 0;
//		}
//	}
//
//	return EXIT_SUCCESS;
//}

