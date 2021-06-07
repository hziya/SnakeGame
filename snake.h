#pragma once

enum direction { stop = 0, left, right, up, down };

//function to check if there is a specific number in an array
bool findInArr(int arr[], int arrSize, int num);


//snake class used to move the snake and store variables for it
class snake
{

public:
	int x, y;                               //position of the snake head
	direction dir = stop;                   //direction of movement
	int tailX[100], tailY[100];             //tail positions with max size 100
	int length = 0;                         //tail length

	//initialize variables
	void initializePos(int x, int y);

	//save the tail
	void saveTail();

	//move the snake according to dir variable
	void move();

	//change direction according to given charachter
	void turn(char c);

};


