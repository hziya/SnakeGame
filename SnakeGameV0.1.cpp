// SnakeGameV0.1.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <conio.h>
#include <windows.h>

enum direction { stop = 0, left, right, up, down };

//function to check if there is a specific number in an array
bool findInArr(int arr[], int arrSize, int num)  {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == num) return true;
    }
    return false;
}


//snake class used to move the snake and store variables for it
class snake {
public:
    int x, y;                               //position of the snake head
    direction dir = stop;                   //direction of movement
    int tailX[100], tailY[100];             //tail positions with max size 100
    int length = 0;                         //tail length

    //initialize variables
    void initializePos (int x, int y) {
        this->x = x;
        this->y = y;
        this->length = 0;
        this->dir = stop;
    }

    //save the tail
    void saveTail() {
        for (int i = length - 1; i > 0; i--) {
            this->tailX[i] = this->tailX[i - 1];
            this->tailY[i] = this->tailY[i - 1];
        }
        tailX[0] = x;
        tailY[0] = y;
    }

    //move the snake according to dir variable
    void move() {
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
    void turn(char c) {
        if (c == 'w' && this->dir != down) this->dir = up;
        if (c == 's' && this->dir != up) this->dir = down;
        if (c == 'd' && this->dir != left) this->dir = right;
        if (c == 'a' && this->dir != right) this->dir = left;
    }

    

};

class feed {
    //random generated feed
public:
    int x, y;
    int width, height;

    //randomly generate a feed
    void newFeed(snake snake) {
        this -> x = std::rand() % width;
        this -> y = std::rand() % height;
        //if the generated feed is on the snake generate new one
        while ((this->x == snake.x && this->y == snake.y) || (findInArr(snake.tailX, snake.length, this->x) && findInArr(snake.tailY, snake.length, this->y))) {
            this->x = std::rand() % width;
            this->y = std::rand() % height;
        }
    }
};


class board {
    //board class draws and realizes the game

private:
    int boardWidth, boardHeight;
    bool playing = true;

public:
    snake snake;
    feed feed;
    board(int width, int height) {
        this->boardWidth = width;
        this->boardHeight = height;
        snake.initializePos(width / 2, height / 2);
        feed.width = width;
        feed.height = height;
        feed.newFeed(snake);
    }

    //reset the class for a new game
    void reset() {
        snake.initializePos(boardWidth / 2, boardHeight / 2);
        feed.width = boardWidth;
        feed.height = boardHeight;
        feed.newFeed(snake);
    }

    void play() {
        playing = true;
        this->reset();
        while (playing) {
            //if keyborad is pressed call the turn function of snake to change direction
            if (_kbhit()) snake.turn(_getch());
            system("CLS");
            snake.move();

            //check if snake crash to somewhere
            if (snake.x >= this->boardWidth || snake.x < 0 || snake.y >= this->boardHeight || snake.y < 0 
                || (findInArr(snake.tailX, snake.length, snake.x) && findInArr(snake.tailY, snake.length, snake.y))) {
                playing = false;
            }
            
            //if snake gets the feed increase its length and generate a new feed
            if (snake.x == feed.x && snake.y == feed.y) {
                snake.length += 1;
                feed.newFeed(snake);
            }

            //draw the game
            this->draw();

            //if snake crushed somewhere end the game
            if (!playing) std::cout << "Game Over \nYour Score is:" << snake.length << "\n";
            else std::cout << "Score:" << snake.length << "\n";

            Sleep(10);
        }
        
    }

    //draw the game to console
    void draw() {
        for (int j = -1; j < this->boardHeight+1; j++) {
            
            for (int i = -1; i < this->boardWidth+1; i++) {
                if (j == -1 || j == boardHeight  || i == -1 || i == boardWidth) std::cout << "#";

                else if (i == snake.x && j == snake.y) std::cout << "O";

                else if (i == feed.x && j == feed.y) std::cout << "*";

                else if (findInArr(snake.tailX, snake.length, i) && findInArr(snake.tailY, snake.length, j)) std::cout << "o";

                else std::cout << " ";

            }
            std::cout << "\n";
        }
    
    }

};





int main()
{
    srand(time(NULL));
    board board(20, 10);
    char c;
    std::cout << "Pres enter to play";
    std::cin.get(c);

    while (c != '\b') {
        
        if (c == '\n') board.play();
        std::cout << "Pres enter to play again";
        std::cin.get(c);
    }

}


