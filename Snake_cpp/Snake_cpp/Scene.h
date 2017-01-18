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
	int tab[101][2]; // tablica zawieraj¹ce wspó³rzêdne bloku food oraz segmentów wê¿a
	string fSign;
	string sSign;
	string state[20][20]; //tablica zawieraj¹ca symbole dla ka¿dego z pól
public:
	Scene(int width, int height);
	void show();
	void updateScene(Food &myFood, Snake &mySnake);
	int getWidth();
	int getHeight();
	int getArea();
	~Scene();
};

