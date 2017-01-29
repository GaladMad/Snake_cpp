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
	Ssystem mySystem(12);

	while (mySystem.getNextGame())
	{
		Scene Background(10, 10); //this is the size of the scene
		Snake mySnake(Background);
		Food myFood(Background, mySnake);
		
		Player newPlayer;

		system("cls");
		string word;
		cout << "Name of player: ";
		cin >> word;
		newPlayer.setName(word);

		while (mySnake.ifAlive() && mySystem.getContinueGame()) {
			system("cls");
			cout << ">>>SNAKE<<<" << endl;
			Background.updateScene(myFood, mySnake);
			Background.show();

			mySnake.setCourse(mySystem.whichButton());
			mySnake.moveSnake();
			myFood.randLocation(mySnake.eatAndGrow(myFood), mySnake); // if snake eats food, the food coordinates change, and the snake grows
			mySystem.refresh();
		}

		newPlayer.setPoints(mySnake.getLength());
		mySystem.createFile(newPlayer);
		cout << "Your score is " << newPlayer.getPoints() << endl;
		mySystem.showResults();

		mySystem.setNextGame(); //if you want you can play one more time
	}

	return 0;
}

