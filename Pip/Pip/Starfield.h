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
	Texture star1Tex;
	Texture star2Tex;

	Sprite star1Sprite;
	Sprite star2Sprite;

	float starSpeed = 1.3;

	float sfY;
	float sf1Y;
	float sf2Y;

	float windowBgDiff;
};
#endif;