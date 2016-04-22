#ifndef STAR_FIELD
#define STAR_FIELD

#include <SFML/Graphics.hpp>

using namespace sf;

class Starfield
{

public:
	Starfield();
	~Starfield();

	void Update();
	void Draw(RenderWindow& window);

private:
	sf::Texture star1Tex;
	sf::Texture star2Tex;

	sf::Sprite star1Sprite;
	sf::Sprite star2Sprite;

	float starSpeed = 1.3;

	float sfY;
	float sf1Y;
	float sf2Y;

	float windowBgDiff;
};
#endif;