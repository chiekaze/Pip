#ifndef SCORE_TEXT 
#define SCORE_TEXT

#include <SFML/Graphics.hpp> 
using namespace sf;

class ScoreText
{
public:
	ScoreText();
	~ScoreText();

	Font font; 
	Text text; 
	int score = 0; 
	
	void Update(); 
	void Draw(sf::RenderWindow &window);
};

#endif;