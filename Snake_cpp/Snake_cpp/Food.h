#pragma once
#include <iostream>
#include "Block.h"
#include "Scene.h"
#include <ctime>
class Scene;
using namespace std;

class Food : public Block
{
	int x;
	int y;
	string foodSign=" x";
public:
	Food(Scene Background);
	string getSign();
	~Food();
};

