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
    //game.render();

    char c {};
    do
    {
        std::cin >> c;
        game.update();
        game.render();

    } while(c != 'q');

    /*
    game.getHead()->setupLine();
    game.render();
    */

    return 0;
}