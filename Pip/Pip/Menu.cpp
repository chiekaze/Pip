#include "Menu.h"
#include <iostream>

Menu::Menu(Player* player)
{
	isPlaying = false;
	font.loadFromFile("fonts/Minecraft.ttf");


	//STARTMENU
	title.setFont(font);
	start.setFont(font);
	quit.setFont(font);
	controls.setFont(font);
	move.setFont(font);
	shoot.setFont(font);
	focus.setFont(font);

	//DEADMENU
	dead.setFont(font);
	restart.setFont(font);
	scoreTxt.setFont(font);
	quit2.setFont(font);

	mPlayer = player;

	//START MENU---------------------------

	//TITLE
	title.setString("PIP: THE GAME");
	title.setCharacterSize(64);
	title.setPosition(Vector2f(160, 100));

	//START
	start.setString("PRESS 'ENTER' TO START");
	start.setCharacterSize(24);
	start.setPosition(Vector2f(230, 300));

	//QUIT
	quit.setString("PRESS 'ESC' TO QUIT");
	quit.setCharacterSize(24);
	quit.setPosition(Vector2f(260, 340));

	//CONTROLS TITLE
	controls.setString("CONTROLS:");
	controls.setCharacterSize(24);
	controls.setPosition(Vector2f(320, 420));

	//CONTROLS
	move.setString("MOVE - ARROW KEYS");
	move.setCharacterSize(16);
	move.setPosition(Vector2f(310, 460));

	shoot.setString("SHOOT - SPACE");
	shoot.setCharacterSize(16);
	shoot.setPosition(Vector2f(330, 480));

	focus.setString("FOCUS - LEFT CTRL");
	focus.setCharacterSize(16);
	focus.setPosition(Vector2f(315, 500));

	//-------------------------------------

	//DEAD
	dead.setString("YOU DIED!");
	dead.setCharacterSize(64);
	dead.setPosition(Vector2f(220, 100));

	scrTxt = new ScoreText();

	scoreTxt.setString("SCORE: " + std::to_string(scrTxt->getScore()));

	scoreTxt.setCharacterSize(48);
	scoreTxt.setPosition(Vector2f(220, 180));

	restart.setString("PRESS 'ENTER' TO PLAY AGAIN");
	restart.setCharacterSize(32);
	restart.setPosition(Vector2f(160, 300));

	quit2.setString("PRESS 'ESC' TO QUIT");
	quit2.setCharacterSize(32);
	quit2.setPosition(Vector2f(230, 360));
}

Menu::~Menu()
{
}

bool Menu::IsPlaying()
{
	return isPlaying;
}

bool Menu::IsNotPlaying()
{
	if (isPlaying == true)
	{
		return false;
	}
	else
		return true;
}

void Menu::StopPlaying()
{
	isPlaying = false;
}

void Menu::StartPlaying()
{
	isPlaying = true;
}

void Menu::Update()
{
	if (Keyboard::isKeyPressed(Keyboard::Return))
	{
		isPlaying = true;
	}

	else
		isPlaying = false;
}

void Menu::UpdateDeadMenu()
{
	scoreTxt.setString("SCORE: " + std::to_string(scrTxt->getScore()));

	if (Keyboard::isKeyPressed(Keyboard::Return))
	{
		isPlaying = true;

		mPlayer->SetPlayerHP(100);
		mPlayer->SetPosition();

		elapsedTime = new ElapsedTime();
		elapsedTime->Reset();
	}

	else
		isPlaying = false;
}

void Menu::Draw(RenderWindow &window)
{
	if (mPlayer->IsAlive())
	{
		window.draw(title);
		window.draw(start);
		window.draw(quit);
		window.draw(controls);
		window.draw(move);
		window.draw(shoot);
		window.draw(focus);
	}
}

void Menu::DrawDeadMenu(RenderWindow &window)
{
	window.draw(dead);
	window.draw(restart);
	window.draw(scoreTxt);
	window.draw(quit2);
}