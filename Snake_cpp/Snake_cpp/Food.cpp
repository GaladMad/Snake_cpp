#include "Food.h"


Food::Food(Scene Background)
{
	maxX = Background.getHeight();
	maxY = Background.getWidth();
	setX(rand() % maxX);
	setY(rand() % maxY);
}

string Food::getSign() {
	return foodSign;
}

void Food::randLocation()
{
	//srand(static_cast<unsigned int> (time(NULL)));
	setX(rand() % maxX);
	setY(rand() % maxY);
}


Food::~Food()
{
}
