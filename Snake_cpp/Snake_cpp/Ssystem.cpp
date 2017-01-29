#include "Ssystem.h"

Snake::course Ssystem::whichButton()
{
	Snake::course newCourse;

	if (_kbhit()) {
		unsigned char znak = _getch();

		switch (znak) {
		case 0: //special buttons
		case 224: //special buttons
			znak = _getch();
			switch (znak) {
			case 72: //UP
				newCourse = Snake::North;
				break;
			case 80: //DOWN
				newCourse = Snake::South;
				break;
			case 77: //RIGHT
				newCourse = Snake::East;
				break;
			case 75: //LEFT
				newCourse = Snake::West;
				break;
			}
			znak = 0;
			break;
		case 27: //ESC
			newCourse = Snake::Other;
			setContinueGame(); //push "y" if you want to continue the game
			break;
		default:
			newCourse = Snake::Other;
			break;
		}
	}
	else {
		newCourse = Snake::Last;
	}

	return newCourse;
}

void Ssystem::createFile(Player newPlayer)
{
	fstream plik;
	plik.open("Scores.txt", ios::app);
	plik << newPlayer.getName() << endl;
	plik << newPlayer.getPoints() << endl;
	plik.close();
}

void Ssystem::showResults()
{
	string yesno;
	cout << "Do you want to see other scores? (y/n):";
	cin >> yesno;

	if (yesno == "y")
	{
		std::fstream plik;
		plik.open("Scores.txt", ios::in);
		if (plik.good())
		{
			int line = 1;
			string napis;
			cout << "\tPlayer\tScore" << endl;
			while (!plik.eof())
			{
				getline(plik, napis);
				if (napis != "") //if the next line is a white sign system does not write more results
				{
					cout << line << ".\t";
					cout << napis << "\t";
					getline(plik, napis);
					cout << napis << endl;
					line++;
				}
			}
			plik.close();
		}
		else cout << "Error! Unable to open the file!" << endl;
	}
	else if(yesno=="n"){	}
	else {
		showResults();
	}
}

void Ssystem::setNextGame()
{
	string yn;
	cout << "Do you want to play one more time? (y/n):";
	cin >> yn;

	if (yn == "y")
	{
		nextGame=true;
	}
	else if (yn == "n")
	{
		nextGame = false;
	}
	else {
		setNextGame();
	}
}

void Ssystem::setContinueGame()
{
	string yn;
	cout << "Do you want to end the game? (y/n):";
	cin >> yn;

	if (yn == "y")
	{
		continueGame=false;
	}
	else if (yn == "n")
	{
		continueGame=true;
	}
	else {
		setContinueGame();
	}
	
}

bool Ssystem::getNextGame()
{
	return nextGame;
}

bool Ssystem::getContinueGame()
{
	return continueGame;
}

void Ssystem::refresh()
{
	Sleep(1000/speed);
}

Ssystem::Ssystem(int sspeed)
{
	nextGame=true;
	continueGame=true;
	speed = sspeed;
}


Ssystem::~Ssystem()
{
}
