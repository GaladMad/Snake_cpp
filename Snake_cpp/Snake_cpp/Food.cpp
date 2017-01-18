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

	/*bool flag = false; // is true if coordinates of food are other than coordinates of segments of snake
	do { //BAD Solution
		setX(rand() % maxX);
		setY(rand() % maxY);

		for (int i = 0; i < mySnake.getLength(); i++) {
			if (getX() == (mySnake.getSegments())[i].getX() && getY() == (mySnake.getSegments())[i].getY()) {
				flag = true;
				break;
			}
		}
	} while (flag);*/

}

string Food::getSign() {
	return foodSign;
}

void Food::randLocation(bool ifEat, Snake &mySnake)
{
	//srand(static_cast<unsigned int> (time(NULL)));
	if (ifEat) {
		int size = maxX*maxY - mySnake.getLength();
		if (size > 0)
		{
			int random = rand() % size;
			setX(possiblePlace(mySnake)[random][0]);
			setY(possiblePlace(mySnake)[random][1]);
		}
		
		//cout << getX() << "	" << getY() << "		rand food bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" << endl;
	}

	//setX(rand() % maxX);
	//setY(rand() % maxY);
	
}


Food::~Food()
{
}
