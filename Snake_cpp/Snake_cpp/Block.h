#pragma once
#include <iostream>
#include <string>
using namespace std;

class Block
{
	int b_x, b_y;
	string blockSign="  ";

public:
	Block();
	Block(int x, int y);
	int getX();
	int getY();
	virtual string getSign();
	void setX(int x);
	void setY(int y);
	~Block();
};

