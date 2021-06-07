#include "snake.h"

bool findInArr(int arr[], int arrSize, int num) {
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] == num) return true;
	}
	return false;
}

void snake::initializePos(int x, int y) {
	this->x = x;
	this->y = y;
	this->length = 0;
	this->dir = stop;
}

//save the tail
void snake::saveTail() {
	for (int i = length - 1; i > 0; i--) {
		this->tailX[i] = this->tailX[i - 1];
		this->tailY[i] = this->tailY[i - 1];
	}
	tailX[0] = x;
	tailY[0] = y;
}

//move the snake according to dir variable
void snake::move() {
	this->saveTail();
	switch (this->dir) {
	case up:
		this->y += -1;
		break;
	case down:
		this->y += +1;
		break;
	case left:
		this->x += -1;
		break;
	case right:
		this->x += 1;
		break;
	}

}

//change direction according to given charachter
void snake::turn(char c) {
	if (c == 'w' && this->dir != down) this->dir = up;
	if (c == 's' && this->dir != up) this->dir = down;
	if (c == 'd' && this->dir != left) this->dir = right;
	if (c == 'a' && this->dir != right) this->dir = left;
}