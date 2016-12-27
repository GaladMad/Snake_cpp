#include <iostream>
#include <string>
#include "Scene.h"
#include "Food.h"

using namespace std;

int main() {
	srand(time(NULL));
	Scene Background(20, 20);
	Food myFood(Background);
	Snake mySnake;
	Background.updateScene(myFood, mySnake);
	Background.show();
	cout << (mySnake.getSegments())[0].getX() <<" " << (mySnake.getSegments())[0].getY() << endl;
	cout << (mySnake.getSegments())[1].getX() << " " << (mySnake.getSegments())[1].getY() << endl;
	cout << (mySnake.getSegments())[2].getX() << " " << (mySnake.getSegments())[2].getY() << endl;
	system("PAUSE");
	return 0;
}