// SnakeGameV0.1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "snake.h"
#include "feed.h"
#include "board.h"



int main()
{
    srand(time(NULL));
    board _board(20, 10);
    char c;
    std::cout << "Pres enter to play";
    std::cin.get(c);

    while (c != '\b') {
        
        if (c == '\n') _board.play();
        std::cout << "Pres enter to play again";
        std::cin.get(c);
    }

}

