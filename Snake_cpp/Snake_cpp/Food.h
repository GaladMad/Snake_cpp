#pragma once
#include <iostream>
#include "Block.h"
#include "Scene.h"
#include <ctime>
class Scene;
using namespace std;

class Food : public Block
{
	int maxX, maxY;
	string foodSign=" x";
public:
	Food(Scene Background);
	string getSign();
	void randLocation();
	~Food();
};

