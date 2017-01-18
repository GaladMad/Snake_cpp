#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include "Scene.h"
#include "Food.h"
#include "Snake.h"
#include "Ssystem.h"

using namespace std;

int main() {
	srand(static_cast<unsigned int> (time(NULL)));
	string nextGame = "y";

	while (nextGame == "y")
	{
		Scene Background(10, 10);
		Snake mySnake(Background);
		Food myFood(Background, mySnake);
		Ssystem mySystem;
		Player newPlayer;

		system("cls");
		string word;
		cout << "Name of player: ";
		cin >> word;
		newPlayer.setName(word);

		while (mySnake.ifAlive()) {
			system("cls");
			cout << "\t>>>SNAKE<<<" << endl;
			Background.updateScene(myFood, mySnake);
			Background.show();
			//cout << myFood.getX() << endl;
			//cout << myFood.getY() << endl;
			//Sleep(500);

			mySnake.setCourse(mySystem.whichButton());
			mySnake.moveSnake();
			myFood.randLocation(mySnake.eatAndGrow(myFood), mySnake); // if snake eat a food, food change coordinate, and snake grown
		}

		newPlayer.setPoints(mySnake.getLength());
		mySystem.createFile(newPlayer);
		cout << "Your results is " << newPlayer.getPoints() << endl;
		mySystem.showResults();

		nextGame = mySystem.newGame(); //if you want, you can play one more time
	}

	system("PAUSE");
	return 0;
}

