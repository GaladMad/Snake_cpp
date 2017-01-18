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
	Block segments[100];
	//Block *segments;// [100]; //table with segents of snake
	string snakeSign = " o";
	int snakeLength;
	Block lastSegment;
	int maxX, maxY;

public:
	enum course
	{	North=0,
		South,
		East,
		West,
		Other
	};
private:
	course snakeCourse; //course wher snake move
	course snakeLastCourse;
	void moveBodyOfSnake();

public:
	Snake(Scene Background);
	string getSign();
	void setCourse(course newCourse);
	course getCourse();
	int getLength();
	Block* getSegments();
	bool ifAlive();
	bool eatAndGrow(Food myFood);
	void moveSnake();
	~Snake();
};

