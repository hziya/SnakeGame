#pragma once
#include <iostream>
#include "snake.h"

class feed {
    //random generated feed
public:
    int x, y;
    int width, height;

    //randomly generate a feed
    void newFeed(snake snake);
};

