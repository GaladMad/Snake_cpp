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
	Block *segments; //table with segments of snake
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
		Last,
		Other
	};
private:
	course snakeCourse; //course where snake moves
	course snakeLastCourse;
	void moveBodyOfSnake();

public:
	Snake(Scene Background);
	string getSign();
	void setCourse(course newCourse);
	course getCourse();
	course getLastCourse();
	int getLength();
	Block* getSegments();
	bool ifAlive();
	bool eatAndGrow(Food myFood);
	void moveSnake();
	~Snake();
};

