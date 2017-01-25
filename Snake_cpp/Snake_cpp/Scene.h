#pragma once
#include <iostream>
#include <string>
#include "Food.h"
#include "Snake.h"
class Food;
class Snake;

using namespace std;

class Scene
{
	int x, y;
	string fSign;
	string sSign;
	//int tab[101][2]; // table with coordination block of food and bloks of snake
	int(*tab)[2];
	//string state[20][20]; //table with sings of every blocks
	string **state;
	
public:
	Scene(int width, int height);
	void show();
	void updateScene(Food &myFood, Snake &mySnake);
	int getWidth();
	int getHeight();
	int getArea();
	~Scene();
};

