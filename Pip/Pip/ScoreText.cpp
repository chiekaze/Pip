#include "ScoreText.h" 
#include <iostream> 

ScoreText::ScoreText() 
{ 
	score;
	totalScore;
	
	font.loadFromFile("fonts/Minecraft.ttf"); 
	text.setFont(font); 
	text.setString("SCORE: " + std::to_string(score)); 
	text.setCharacterSize(22); 
	text.setPosition(Vector2f(5, 5)); 
} 

ScoreText::~ScoreText() 
{ 
} 

void ScoreText::Update()
{ 
	text.setString("SCORE: " + std::to_string(++score)); 
	totalScore = score;
}

int ScoreText::getScore()
{
	return totalScore;
}

void ScoreText::Draw(RenderWindow &window) 
{ 
	window.draw(text); 
}