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
	int(*coordinationOfFoodAndSnake)[2]; // table with coordination block of food and blocks of snake
	string **signsOfEveryBlock; //table with signs of every block
	
public:
	Scene(int width, int height);
	void show();
	void updateScene(Food &myFood, Snake &mySnake);
	int getWidth();
	int getHeight();
	int getArea();
	~Scene();
};

