#pragma once
#include <windows.h>
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
    snake snake;
    feed feed;

    //constructor function
    board(int width, int height);

    
    //function to play the game
    void play();

    

};

