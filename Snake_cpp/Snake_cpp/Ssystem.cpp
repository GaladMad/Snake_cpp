#include "Ssystem.h"

Snake::course Ssystem::whichButton()
{
		Snake::course newCourse;
		bool end = false;
		//while (end == false)
		//{
		unsigned char znak = _getch();

		switch (znak) {
		case 0: //special buttons
		case 224: //special buttons
			znak = _getch();
			switch (znak) {
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
			//case 27: //ESC
			//end = true;
			//break;
		default:
			newCourse = Snake::Other;
			break;
		}
		//}
		return newCourse;
}

void Ssystem::createFile(Player newPlayer)
{
	fstream plik;
	plik.open("Results.txt", ios::app);
	plik << newPlayer.getName() << endl;
	plik << newPlayer.getPoints() << endl;
	plik.close();
}

void Ssystem::showResults()
{
	string yesno;
	cout << "Do you want to see other results (y/n):";
	cin >> yesno;

	if (yesno == "y")
	{
		std::fstream plik;
		plik.open("Results.txt", ios::in);
		if (plik.good())
		{
			int line = 1;
			string napis;
			cout << "\tPlayer\tResult" << endl;
			while (!plik.eof())
			{
				getline(plik, napis);
				if (napis != "") //if next line is white sign system not write more results
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
		else cout << "Error! Unable to open file!" << endl;
	}
}

string Ssystem::newGame()
{
	string yn;
	cout << "Do you want play one more time? (y/n):";
	cin >> yn;

	if (yn == "y")
	{
		return "y";
	}
	else
	{
		return "n";
	}
}

Ssystem::Ssystem()
{
}


Ssystem::~Ssystem()
{
}
