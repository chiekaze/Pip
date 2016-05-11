#ifndef BACK_GROUND
#define BACK_GROUND

#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;

class Background
{

public:
	Background(Player* player);
	~Background();

	void Update();
	void Draw(RenderWindow& window);

private:
	Player* mPlayer;

	Texture bg1Tex;
	Texture bg2Tex;
	
	Vector2f bgSize;
	
	Sprite bg1Sprite;
	Sprite bg2Sprite;
	
	float bgNormalSpeed;
	float bgSpeed;
	
	float bgY;
	float bg1Y;
	float bg2Y;

	float windowBgDiff;
};
#endif;