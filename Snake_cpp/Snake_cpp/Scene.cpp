#include "Scene.h"

Scene::Scene(int width, int height)
{
	x = width;
	y = height;
	coordinationOfFoodAndSnake = new int[x*y+1][2];

	signsOfEveryBlock = new string*[x];
	for (int i = 0; i < x; i++) {
		signsOfEveryBlock[i] = new string[y];
	}
}

void Scene::show() {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << signsOfEveryBlock[i][j];
		}
		cout << endl;
	}
}

void Scene::updateScene(Food &myFood, Snake &mySnake) {
	coordinationOfFoodAndSnake[0][0] = myFood.getX();
	coordinationOfFoodAndSnake[0][1] = myFood.getY();
	fSign = myFood.getSign();
	sSign = mySnake.getSign();

	for (int i = 0; i < mySnake.getLength(); i++) {
		coordinationOfFoodAndSnake[i + 1][0] = (mySnake.getSegments())[i].getX();
		coordinationOfFoodAndSnake[i + 1][1] = (mySnake.getSegments())[i].getY();
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
				signsOfEveryBlock[i][j] = " .";
		}
	}

	signsOfEveryBlock[coordinationOfFoodAndSnake[0][0]][coordinationOfFoodAndSnake[0][1]] = fSign;

	for (int i = 0; i < mySnake.getLength(); i++) {
		signsOfEveryBlock[coordinationOfFoodAndSnake[i+1][0]][coordinationOfFoodAndSnake[i+1][1]] = sSign;
	}
}

int Scene::getWidth() {
	return x;
}

int Scene::getHeight() {
	return y;
}

int Scene::getArea()
{
	return x*y;
}

Scene::~Scene()
{
	system("cls");
	delete[] coordinationOfFoodAndSnake;
	/*for (int i = 0; i < x; i++) {
		delete[] state[i];
	}
	delete[] state;*/
}
