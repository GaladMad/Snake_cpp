#pragma once
#include <iostream>
#include "Block.h"
#include "Scene.h"
#include <ctime>
class Scene;
class Snake;
using namespace std;

class Food : public Block
{
	int maxX, maxY;
	string foodSign=" x";

public:
	int** possiblePlace(Snake &mySnake);
	Food(Scene &Background, Snake &mySnake);
	string getSign();
	void randLocation(bool ifeat, Snake &mySnake);
	~Food();
};

