#ifndef SCORE_TEXT 
#define SCORE_TEXT

#include <SFML/Graphics.hpp> 
using namespace sf;

class ScoreText
{
public:
	ScoreText();
	~ScoreText();

	void Update();
	void Draw(RenderWindow &window);

private:
	Font font; 
	Text text; 
	int score = 0; 
};

#endif;