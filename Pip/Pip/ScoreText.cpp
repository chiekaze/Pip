#include "ScoreText.h" 
#include <iostream> 

ScoreText::ScoreText() 
{ 
	font.loadFromFile("fonts/Minecraft.ttf"); 
	text.setFont(font); text.setString("SCORE: " + std::to_string (score)); 
	text.setCharacterSize(22); 
	text.setPosition(Vector2f(5, 5)); 
} 
ScoreText::~ScoreText() 
{ 

} 

int ScoreText::getScore()
{
	return score;
}

void ScoreText::Update()
{ 
	text.setString("SCORE: " + std::to_string(++score)); 
}

void ScoreText::Draw(RenderWindow &window) 
{ 
	window.draw(text); 
}