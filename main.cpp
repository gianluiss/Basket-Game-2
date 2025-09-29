#include "Sky.h"
#include "Game.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(nullptr));

    Game game;

    game.initializeSky();
    game.render();

    while(game.isRunning())
    {
        game.handleInput();
        game.update();
        game.render();
    }

    return 0;
}