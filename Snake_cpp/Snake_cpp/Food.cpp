#include "Food.h"


int ** Food::possiblePlace(Snake & mySnake)
{
	int **tableOfPossiblePlace = new int*[maxX * maxY - mySnake.getLength()];

	for (int i = 0, k=0; i < maxX; i++) {
		for (int j = 0; j < maxY; j++) { // two loops used because scene has got two dimensions
			bool flag = true;
				for (int s = 0; s < mySnake.getLength(); s++) {

					if (i == (mySnake.getSegments())[s].getX() && j == (mySnake.getSegments())[s].getY()) {
						flag = false;
					}
				}
			///////////////////////
			//if any segment of snake or old food has [i,j] coordinates, set these numbers into table
			if (flag) {
				tableOfPossiblePlace[k] = new int[2];
				tableOfPossiblePlace[k][0] = i;
				tableOfPossiblePlace[k][1] = j;
				k++;
			}
		}
		
	}
	return tableOfPossiblePlace;
}

Food::Food(Scene &Background, Snake &mySnake)
{
	maxX = Background.getHeight();
	maxY = Background.getWidth();
	
	randLocation(1, mySnake);
}

string Food::getSign() {
	return foodSign;
}

void Food::randLocation(bool ifEat, Snake &mySnake)
{
	if (ifEat) {
		int size = maxX*maxY - mySnake.getLength();
		if (size > 0)
		{
			int random = rand() % size;
			setX(possiblePlace(mySnake)[random][0]);
			setY(possiblePlace(mySnake)[random][1]);
		}
	}
}


Food::~Food()
{

}
