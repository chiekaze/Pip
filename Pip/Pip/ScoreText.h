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
	void addScore(int scr);
	void writeScore();

	void Update();
	void Draw(RenderWindow &window);

private:
	Font font; 
	Text text;

	int score;
	int totalScore;

};

#endif;