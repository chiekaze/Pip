#ifndef STAR_FIELD
#define STAR_FIELD

#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;

class Starfield
{

public:
	Starfield(Player* player);
	~Starfield();

	void Update();
	void Draw(RenderWindow& window);

private:
	Player* mPlayer;

	Texture star1Tex;
	Texture star2Tex;

	Sprite star1Sprite;
	Sprite star2Sprite;

	float starNormalSpeed;
	float starSpeed;

	float sfY;
	float sf1Y;
	float sf2Y;

	float windowBgDiff;
};
#endif;