#include "Snake.h"

Snake::Snake()
{
	Block segment0(0, 0);
	Block segment1(0, 1);
	Block segment2(0, 2);

	segments[0] = segment0;
	segments[1] = segment1;
	segments[2] = segment2;

	//for (int i = 3; i <= 100; i++) {
	//	segments[i] = NULL;
	//}

	snakeCourse = East;
	snakeLength = 3;
}

string Snake::getSign() {
	return snakeSign;
}

void Snake::setCourse(course newCourse)
{
	snakeCourse = newCourse;
}

Snake::course Snake::getCourse()
{
	return snakeCourse;
}

int Snake::getLength()
{
	return snakeLength;
}

Block* Snake::getSegments()
{
	return segments;
}


Snake::~Snake()
{
}
