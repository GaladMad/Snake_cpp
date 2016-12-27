#include "Block.h"


Block::Block() {

}

Block::Block(int x, int y){
	b_x = x;
	b_y = y;
}

int Block::getX() {
	return b_x;
}

int Block::getY() {
	return b_y;
}

string Block::getSign() {
	return blockSign;
}

void Block::setX(int x) {
	b_x = x;
}

void Block::setY(int y) {
	b_y = y;
}


Block::~Block()
{
}
