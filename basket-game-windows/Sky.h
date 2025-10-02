#ifndef SKY_H
#define SKY_H 

#include <iostream>

struct Sky
{
    const int lineSize {40};
    const int itemsPerLine {2};
    std::string line {std::string(lineSize, ' ')};
    Sky* next {nullptr};

    void setupLine(); //generate random objects within line
};

#endif
