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

	int score = 0;
	int totalScore = score;

private:
	Font font; 
	Text text; 

};

#endif;