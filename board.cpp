#include "board.h"

board::board(int width, int height) {
    this->boardWidth = width;
    this->boardHeight = height;
    snake.initializePos(width / 2, height / 2);
    feed.width = width;
    feed.height = height;
    feed.newFeed(snake);
}

//reset the class for a new game
void board::reset() {
    snake.initializePos(boardWidth / 2, boardHeight / 2);
    feed.width = boardWidth;
    feed.height = boardHeight;
    feed.newFeed(snake);
}

void board::play() {
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

        Sleep(500);
    }

}

//draw the game to console
void board::draw() {
    for (int j = -1; j < this->boardHeight + 1; j++) {

        for (int i = -1; i < this->boardWidth + 1; i++) {
            if (j == -1 || j == boardHeight || i == -1 || i == boardWidth) std::cout << "#";

            else if (i == snake.x && j == snake.y) std::cout << "O";

            else if (i == feed.x && j == feed.y) std::cout << "*";

            else if (findInArr(snake.tailX, snake.length, i) && findInArr(snake.tailY, snake.length, j)) std::cout << "o";

            else std::cout << " ";

        }
        std::cout << "\n";
    }

}