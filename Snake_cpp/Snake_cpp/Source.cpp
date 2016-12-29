#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include "Scene.h"
#include "Food.h"
#include "Snake.h"

/*
gora 224 72
dol 224 80
prawo 224 77
lewo 224 75
esc 27
*/

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
				cout << "N";
				break;
			case 80: //DOWN
				newCourse = Snake::South;
				cout << "S";
				break;
			case 77: //RIGHT
				newCourse = Snake::East;
				cout << "E";
				break;
			case 75: //LEFT
				newCourse = Snake::West;
				cout << "W";
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
	Snake mySnake;

	//unsigned char symbol;

	for (int i = 0; i < 10; i++) {
		system("cls");
		Background.updateScene(myFood, mySnake);
		Background.show();
		//Sleep(500);

		mySnake.setCourse(whichButton());
		//mySnake.setCourse(Snake::South);
		mySnake.moveSnake();
	}
	

	cout << (mySnake.getSegments())[0].getX() <<" " << (mySnake.getSegments())[0].getY() << endl;
	cout << (mySnake.getSegments())[1].getX() << " " << (mySnake.getSegments())[1].getY() << endl;
	cout << (mySnake.getSegments())[2].getX() << " " << (mySnake.getSegments())[2].getY() << endl;
	system("PAUSE");
	return 0;
}

