#include "ScoreText.h" 
#include <iostream>
#include <fstream>

using namespace std;

ScoreText::ScoreText() 
{ 
	score = 0;
	totalScore = score;
	
	font.loadFromFile("fonts/Minecraft.ttf"); 
	text.setFont(font); 
	text.setString("SCORE: " + to_string(score)); 
	text.setCharacterSize(22); 
	text.setPosition(Vector2f(5, 5));
} 

ScoreText::~ScoreText() 
{ 
} 

void ScoreText::Update()
{ 
	text.setString("SCORE: " + to_string(score));
	totalScore = score;
}

void ScoreText::addScore(int scr)
{
	text.setString("SCORE: " + to_string(score += scr));
}

int ScoreText::getScore()
{
	return score;
}

void ScoreText::writeScore()
{
	totalScore = score;
	ofstream scoreFile;
	scoreFile.open("kebab.txt");
	scoreFile << to_string(totalScore);
	scoreFile.close();
}

void ScoreText::Draw(RenderWindow &window) 
{ 
	window.draw(text); 
}