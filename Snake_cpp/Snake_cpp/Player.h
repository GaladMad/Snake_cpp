#pragma once
#include <iostream>
#include <string>

using namespace std;

class Player
{
	string Pname;
	int Ppoints;

public:
	Player();
	void setName(string name);
	string getName();
	void setPoints(int points);
	int getPoints();
	~Player();
};

