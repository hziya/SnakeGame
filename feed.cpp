#include "feed.h"

//randomly generate a feed
void feed::newFeed(snake snake) {
    this->x = std::rand() % width;
    this->y = std::rand() % height;
    //if the generated feed is on the snake generate new one
    while ((this->x == snake.x && this->y == snake.y) || (findInArr(snake.tailX, snake.length, this->x) && findInArr(snake.tailY, snake.length, this->y))) {
        this->x = std::rand() % width;
        this->y = std::rand() % height;
    }
}