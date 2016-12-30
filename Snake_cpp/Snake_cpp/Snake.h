#pragma once
#include <iostream>
#include "Block.h"
#include "Scene.h"
#include "Food.h"
using namespace std;

class Food;
class Block;
class Scene;

class Snake
{
	Block segments[100]; //table with segents of snake
	string snakeSign = " o";
	int snakeLength;
	Block lastSegment;
	int maxX, maxY;

public:
	enum course
	{	North=0,
		South,
		East,
		West
	};
private:
	course snakeCourse; //course wher snake move
	void moveBodyOfSnake();

public:
	Snake(Scene Background);
	string getSign();
	void setCourse(course newCourse);
	course getCourse();
	int getLength();
	Block* getSegments();
	bool ifAlive();
	void eatAndGrow(Food myFood);
	void moveSnake();
	~Snake();
};

