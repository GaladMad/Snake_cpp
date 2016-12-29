#pragma once
#include <iostream>
#include "Block.h"
#include "Scene.h"
using namespace std;

class Snake
{
	Block segments[100]; //table with segents of snake
	string snakeSign = " o";
	int snakeLength;

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
	Snake();
	string getSign();
	void setCourse(course newCourse);
	course getCourse();
	int getLength();
	Block* getSegments();
	bool ifAlive();
	void moveSnake();
	~Snake();
};

