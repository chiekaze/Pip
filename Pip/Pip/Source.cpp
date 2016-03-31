#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	int width = 800;
	int height = 600;
	
	float playerSpeed;
	float playerNormalSpeed = 0.05;
	float playerFocusSpeed = 0.025;
	
	int playerSize = 5;
	int projectileSize = 3;
	
	float projectileSpeed = 0.05;

	//Playarea border sizes
	int borderSize = 10;

	RenderWindow window(VideoMode(width, height), "Pip");

	//Playarea
	RectangleShape top, bottom, right, left;

	top.setPosition(0, -borderSize);
	top.setSize(Vector2f(width, borderSize));
	top.setFillColor(Color::White);

	bottom.setPosition(0, height);
	bottom.setSize(Vector2f(width, borderSize));
	bottom.setFillColor(Color::White);

	right.setPosition(width, 0);
	right.setSize(Vector2f(borderSize, height));
	right.setFillColor(Color::White);

	left.setPosition(-borderSize, 0);
	left.setSize(Vector2f(borderSize, height));
	left.setFillColor(Color::White);
	
	//Player
	CircleShape player(playerSize);
	
	player.setFillColor(Color::White);
	player.setPosition(width / 2, height / 2);
	
	//Projectile
	CircleShape projectile(projectileSize);
	projectile.setFillColor(Color::Yellow);
	projectile.setPosition(player.getPosition());

	while (window.isOpen())
	{
		window.clear(Color::Black);
		
		window.draw(player);
		window.draw(top);
		window.draw(bottom);
		window.draw(right);
		window.draw(left);
		window.draw(projectile);
		window.display();

		Event event;
		while (window.pollEvent(event))
		{
			if ((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
				window.close();
		}

		//Movement
		if (Keyboard::isKeyPressed(Keyboard::Z))
			playerSpeed = playerFocusSpeed;
		else
			playerSpeed = playerNormalSpeed;

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			//Collision checks
			FloatRect playerBoundingBox = player.getGlobalBounds();
			FloatRect leftBoundingBox = left.getGlobalBounds();

			if (playerBoundingBox.intersects(leftBoundingBox))
			{
				player.move(0, 0);
			}

			else
				player.move(-playerSpeed, 0);
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			//Collision checks
			FloatRect playerBoundingBox = player.getGlobalBounds();
			FloatRect rightBoundingBox = right.getGlobalBounds();

			if (playerBoundingBox.intersects(rightBoundingBox))
			{
				player.move(0, 0);
			}

			else
				player.move(playerSpeed, 0);
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			//Collision checks
			FloatRect playerBoundingBox = player.getGlobalBounds();
			FloatRect topBoundingBox = top.getGlobalBounds();

			if (playerBoundingBox.intersects(topBoundingBox))
			{
				player.move(0, 0);
			}

			else
				player.move(0, -playerSpeed);
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			//Collision checks
			FloatRect playerBoundingBox = player.getGlobalBounds();
			FloatRect bottomBoundingBox = bottom.getGlobalBounds();

			if (playerBoundingBox.intersects(bottomBoundingBox))
			{
				player.move(0, 0);
			}

			else
				player.move(0, playerSpeed);
		}

		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			projectile.move(0, -projectileSpeed);
		}
	}

	return EXIT_SUCCESS;
}