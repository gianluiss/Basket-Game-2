#include "Sky.h"
#include "Game.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

#include <ncurses.h>
#include <unistd.h>

int main()
{
    std::srand(std::time(nullptr));

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    nodelay(stdscr, TRUE);

    Game game;
    game.initializeSky();
    game.render();

    while(game.isRunning())
    {
        int input = getch();

        game.handleInput(input);
        game.update();

        clear();
        game.render();
        refresh();

        //33000 = 30 fps
        //16000 = 60 fps
        usleep(210000);
    }

    endwin();

    std::cout << "Your Score: " << game.getScore() << '\n';

    if(game.getScore() >= 100)
        std::cout << "Yeah, you win!!\n";
    else if(game.getScore() <= 0)
        std::cout << "Sorry, you lose...\n";
    else
        std::cout << "Error. program ended with invalid score\n";


    return 0;
}