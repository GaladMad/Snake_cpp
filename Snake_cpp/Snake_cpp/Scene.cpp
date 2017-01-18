#include "Scene.h"

Scene::Scene(int width, int height)
{
	x = width;
	y = height;
}

void Scene::show() {
	for (int i = 0; i < x; i++) {
		//state[i] = new string[y];
		for (int j = 0; j < y; j++) {
			cout << state[i][j];
		}
		cout << endl;
	}
}

void Scene::updateScene(Food &myFood, Snake &mySnake) {
	tab[0][0] = myFood.getX();
	tab[0][1] = myFood.getY();
	fSign = myFood.getSign();
	sSign = mySnake.getSign();

	for (int i = 0; i < mySnake.getLength(); i++) {
		tab[i + 1][0] = (mySnake.getSegments())[i].getX();
		tab[i + 1][1] = (mySnake.getSegments())[i].getY();
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
				state[i][j] = " ."; /////////////////////sign
		}
	}

	state[tab[0][0]][tab[0][1]] = fSign;

	for (int i = 0; i < mySnake.getLength(); i++) {
		state[tab[i+1][0]][tab[i+1][1]] = sSign;
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
}
