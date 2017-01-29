#include "Snake.h"

Snake::Snake(Scene Background)
{
	maxX = Background.getHeight();
	maxY = Background.getWidth();

	segments = new Block[maxX*maxY];

	Block segment0(0, 2);
	Block segment1(0, 1);
	Block segment2(0, 0);

	segments[0] = segment0;
	segments[1] = segment1;
	segments[2] = segment2;

	snakeCourse = East;
	snakeLastCourse = East;
	snakeLength = 3;
}

string Snake::getSign() {
	return snakeSign;
}

void Snake::setCourse(course newCourse)
{
	if (newCourse == Last) {
		snakeCourse = snakeLastCourse; // if another button was pushed, do not change the course
	}
	else {
		snakeCourse = newCourse;
	}
	
}

Snake::course Snake::getCourse()
{
	return snakeCourse;
}

Snake::course Snake::getLastCourse()
{
	return snakeLastCourse;
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

bool Snake::eatAndGrow(Food myFood)
{
	if ((segments[0].getX() == myFood.getX()) && (segments[0].getY() == myFood.getY())) {
		snakeLength++;
		segments[snakeLength - 1].setX(lastSegment.getX());//add last segment to segments
		segments[snakeLength - 1].setY(lastSegment.getY());
		return true;
	}
	else { return false; }
}

void Snake::moveBodyOfSnake() {
	lastSegment.setX(segments[snakeLength - 1].getX()); // set coordinates of the last segment
	lastSegment.setY(segments[snakeLength - 1].getY());

	for (int i = snakeLength-1; i > 0; i--) {
		segments[i].setX(segments[i - 1].getX());
		segments[i].setY(segments[i - 1].getY());
	}
}

void Snake::moveSnake()
{
	switch (snakeCourse){
	case North: //if course is set up, snake moves up
		if (snakeLastCourse != South)
		{
			moveBodyOfSnake();

			if (segments[0].getX() == 0) { //if snake goes outside the scene, it appears on the bottom of the scene
				segments[0].setX(maxX - 1);
			}
			else {
				segments[0].setX(segments[0].getX() - 1);
			}
			snakeLastCourse = North;
		}
		break;
	case South: //if course is set down, snake moves down
		if (snakeLastCourse != North)
		{
			moveBodyOfSnake();

			if (segments[0].getX() == (maxX - 1)) { //if snake goes outside the scene, it appears on the top of the scene
				segments[0].setX(0);
			}
			else {
				segments[0].setX(segments[0].getX() + 1);
			}
			snakeLastCourse = South;
		}
		break;

	case East: //if course is set to left, snake moves left
		if (snakeLastCourse != West)
		{
			moveBodyOfSnake();

			if (segments[0].getY() == (maxX - 1)) { //if snake goes outside of the scene, it appears on the right of the scene
				segments[0].setY(0);
			}
			else {
				segments[0].setY(segments[0].getY() + 1);
			}
			snakeLastCourse = East;
		}
		break;

	case West: //if course is set to right, snake moves right
		if (snakeLastCourse != East)
		{
			moveBodyOfSnake();

			if (segments[0].getY() == 0) { //if snake goes outside of the scene, it appears on the left of the scene
				segments[0].setY(maxX - 1);
			}
			else {
				segments[0].setY(segments[0].getY() - 1);
			}
			snakeLastCourse = West;
		}
		break;

	default: //if course is different, do nothing
		break;
	}
}


Snake::~Snake()
{
	delete[] segments;
}
