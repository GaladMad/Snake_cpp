#include "Snake.h"

Snake::Snake()
{
	Block segment0(0, 2);
	Block segment1(0, 1);
	Block segment2(0, 0);

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

bool Snake::ifAlive()
{
	bool alive = true;
	for (int i = 2; i < snakeLength; i++) {
		if ((segments[0].getX() == segments[i].getX()) && (segments[0].getY() == segments[i].getY())) {
			alive = false;
			break;
		}
	}

	return alive;
}

void Snake::moveBodyOfSnake() {
	for (int i = snakeLength-1; i > 0; i--) {
		segments[i].setX(segments[i - 1].getX());
		segments[i].setY(segments[i - 1].getY());
	}
}

void Snake::moveSnake()
{
	switch (snakeCourse){
	case North: //if course is set to up, snake move to up
		moveBodyOfSnake();
		segments[0].setX(segments[0].getX() - 1);

		break;
	case South: //if course is set to down, snake move to down
		moveBodyOfSnake();
		segments[0].setX(segments[0].getX() + 1);
		break;

	case East: //if course is set to left, snake move to left
		moveBodyOfSnake();
		segments[0].setY(segments[0].getY() + 1);
		break;

	case West: //if course is set to right, snake move to right
		moveBodyOfSnake();
		segments[0].setY(segments[0].getY() - 1);
		break;
	default:
		break;
	}
}


Snake::~Snake()
{
}
