#include "Food.h"


int ** Food::possiblePlace(Snake & mySnake) //TO CORRECT
{
	//int lengthOfTable = Background.getArea() - mySnake.getLength();
	int **table = new int*[maxX * maxY - mySnake.getLength()];

	for (int i = 0, k=0; i < maxX; i++) {
		for (int j = 0; j < maxY; j++) { // use two loop because scene has got a two dimension
			bool flag = true;
				for (int s = 0; s < mySnake.getLength(); s++) {

					if (i == (mySnake.getSegments())[s].getX() && j == (mySnake.getSegments())[s].getY()) {
						flag = false;
					}
				}
			///////////////////////
			//if any segments of snake or old food have a [i,j] coordinates, set this numbers to table
			if (flag) {
				table[k] = new int[2];
				table[k][0] = i;
				table[k][1] = j;
				k++;
			}
		}
		
	}
	return table;
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
