#pragma once
#include <iostream>
#include <conio.h>
#include "Snake.h"
#include "Player.h"
#include <fstream>

using namespace std;

class Ssystem
{
public:
	Ssystem();
	Snake::course whichButton();
	void createFile(Player newPlayer);
	void showResults();
	string newGame();
	~Ssystem();
};

