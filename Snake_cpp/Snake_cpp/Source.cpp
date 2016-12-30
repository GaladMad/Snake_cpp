#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include "Scene.h"
#include "Food.h"
#include "Snake.h"

using namespace std;

Snake::course whichButton() { //WYMAGA DOPRACOWANIA!!!
	Snake::course newCourse;
	bool end = false;
	//while (end == false)
	//{
		unsigned char znak = _getch();

		switch (znak){
		case 0: //special buttons
		case 224: //special buttons
			znak = _getch();
			switch (znak){
			case 72: //UP
				newCourse = Snake::North;
				//cout << "N";
				break;
			case 80: //DOWN
				newCourse = Snake::South;
				//cout << "S";
				break;
			case 77: //RIGHT
				newCourse = Snake::East;
				//cout << "E";
				break;
			case 75: //LEFT
				newCourse = Snake::West;
				//cout << "W";
				break;
			}
			znak = 0;
			break;
			//case 13: //ENTER
			//break;
		case 27: //ESC
			end = true;
			break;
		default:
			break;
		}
	//}
		return newCourse;
}

int main() {
	srand(static_cast<unsigned int> (time(NULL)));
	Scene Background(20, 20);
	Food myFood(Background);
	Snake mySnake(Background);

	while (mySnake.ifAlive()) {
		system("cls");
		cout << "		>>>SNAKE<<<" << endl;
		Background.updateScene(myFood, mySnake);
		Background.show();
		cout << myFood.getX() << endl;
		cout << myFood.getY() << endl;
		//Sleep(500);

		mySnake.setCourse(whichButton());
		mySnake.moveSnake();
		mySnake.eatAndGrow(myFood);

		//myFood.randLocation();
	}
	

	cout << (mySnake.getSegments())[0].getX() << " " << (mySnake.getSegments())[0].getY() << endl;
	cout << (mySnake.getSegments())[1].getX() << " " << (mySnake.getSegments())[1].getY() << endl;
	cout << (mySnake.getSegments())[2].getX() << " " << (mySnake.getSegments())[2].getY() << endl;
	system("PAUSE");
	return 0;
}

