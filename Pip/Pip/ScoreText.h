#ifndef SCORE_TEXT 
#define SCORE_TEXT

#include <SFML/Graphics.hpp> 
#include <string> 
using namespace sf;

class ScoreText
{
public:
	ScoreText();
	~ScoreText();

	int getScore();

	void Update();
	void Draw(RenderWindow &window);

private:
	Font font; 
	Text text; 
	int score = 0; 
	int totalScore = score;
};

#endif;