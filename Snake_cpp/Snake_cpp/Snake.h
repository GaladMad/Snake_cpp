#pragma once
#include <iostream>
#include "Block.h"
#include "Scene.h"
using namespace std;

class Snake
{
	Block segments[100];
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
	course snakeCourse;

public:
	Snake();
	string getSign();
	void setCourse(course newCourse);
	course getCourse();
	int getLength();
	Block* getSegments();
	~Snake();
};

