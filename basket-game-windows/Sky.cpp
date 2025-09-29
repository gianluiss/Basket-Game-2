#include "Sky.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

void Sky::setupLine()
{
    for(int i = 0; i < lineSize; i++)
    {
        int state = std::rand() % 100 + 1;

        if(state > 100 || state < 0)
        {
            std::cerr << "Error. Invalid State\n";
            return;
        }



        // handle object chances here
        if(state >= 97 && state <= 98)
            line[i] = '$';

        if(state >= 99 && state <= 100)
            line[i] = '.';
    }
}