#include "board.h"

board::board(int width, int height) {
    this->boardWidth = width;
    this->boardHeight = height;
    _snake.initializePos(width / 2, height / 2);
    _feed.width = width;
    _feed.height = height;
    _feed.newFeed(_snake);
}

//reset the class for a new game
void board::reset() {
    _snake.initializePos(boardWidth / 2, boardHeight / 2);
    _feed.width = boardWidth;
    _feed.height = boardHeight;
    _feed.newFeed(_snake);
}

void board::play() {
    playing = true;
    this->reset();
    while (playing) {
        //if keyborad is pressed call the turn function of _snake to change direction
        if (_kbhit()) _snake.turn(_getch());
        system("CLS");
        _snake.move();

        //check if _snake crash to somewhere
        if (_snake.x >= this->boardWidth || _snake.x < 0 || _snake.y >= this->boardHeight || _snake.y < 0) {
            playing = false;
        }
        //if crashed to its tail
        auto foundX = findInArr(_snake.tailX, _snake.length, _snake.x);
        auto foundY = findInArr(_snake.tailY, _snake.length, _snake.y);
        if(foundX != -1 && foundX == foundY){
            playing = false;
        }

        //if _snake gets the _feed increase its length and generate a new _feed
        if (_snake.x == _feed.x && _snake.y == _feed.y) {
            _snake.length += 1;
            _feed.newFeed(_snake);
        }

        //draw the game
        this->draw();

        //if _snake crushed somewhere end the game
        if (!playing) std::cout << "Game Over \nYour Score is:" << _snake.length << "\n";
        else std::cout << "Score:" << _snake.length << "\n";

        sleep(500);
    }

}

//draw the game to console
void board::draw() {
    for (int j = -1; j < this->boardHeight + 1; j++) {

        for (int i = -1; i < this->boardWidth + 1; i++) {
            if (j == -1 || j == boardHeight || i == -1 || i == boardWidth) std::cout << "#";

            else if (i == _snake.x && j == _snake.y) std::cout << "O";

            else if (i == _feed.x && j == _feed.y) std::cout << "*";

            else if (findInArr(_snake.tailX, _snake.length, i) && findInArr(_snake.tailY, _snake.length, j)) std::cout << "o";

            else std::cout << " ";

        }
        std::cout << "\n";
    }

}