#pragma once
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <conio.h>
#include "snake.h"
#include "feed.h"

class board {
    //board class draws and realizes the game

private:
    int boardWidth, boardHeight;
    bool playing = true;

    //draw the game to console
    void draw();

    //reset the class for a new game
    void reset();

public:
    snake _snake;
    feed _feed;

    //constructor function
    board(int width, int height);

    
    //function to play the game
    void play();

    

};

