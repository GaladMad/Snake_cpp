#include "Food.h"


Food::Food(Scene Background)
{
	//x = rand() % (Background.getHeight);
	//y = rand() % (Background.getWidth);
	setX(rand() % 20);
	setY(rand() % 20);
}

string Food::getSign() {
	return foodSign;
}


Food::~Food()
{
}
