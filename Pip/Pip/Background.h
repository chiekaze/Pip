#ifndef BACK_GROUND
#define BACK_GROUND

#include <SFML/Graphics.hpp>

using namespace sf;

class Background
{

public:
	Background();
	~Background();

	void Update();
	void Draw(RenderWindow& window);

private:
	Texture bg1Tex;
	Texture bg2Tex;
	
	Vector2f bgSize;
	
	Sprite bg1Sprite;
	Sprite bg2Sprite;
	
	float bgSpeed = 1;
	
	float bgY;
	float bg1Y;
	float bg2Y;

	float windowBgDiff;
};
#endif;