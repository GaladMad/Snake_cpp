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
	int tab[101][2]; // tablica zawieraj�ce wsp�rz�dne bloku food oraz segment�w w�a
	string fSign;
	string sSign;
	string state[20][20]; //tablica zawieraj�ca symbole dla ka�dego z p�l
public:
	Scene(int width, int height);
	void show();
	void updateScene(Food &myFood, Snake &mySnake);
	int getWidth();
	int getHeight();
	int getArea();
	~Scene();
};

