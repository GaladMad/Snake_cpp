#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Snake.h"
#include "Player.h"
#include <fstream>

using namespace std;

class Ssystem
{
	bool nextGame;
	bool continueGame;
	int speed;
public:
	Ssystem(int sspeed);
	Snake::course whichButton();
	void createFile(Player newPlayer);
	void showResults();
	void setNextGame();
	void setContinueGame();
	bool getNextGame();
	bool getContinueGame();
	void refresh();
	~Ssystem();
};

