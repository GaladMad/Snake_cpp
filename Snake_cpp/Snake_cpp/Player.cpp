#include "Player.h"

Player::Player()
{
}

void Player::setName(string name)
{
	Pname = name;
}

string Player::getName()
{
	return Pname;
}

void Player::setPoints(int points)
{
	Ppoints = points;
}

int Player::getPoints()
{
	return Ppoints;
}


Player::~Player()
{
}
