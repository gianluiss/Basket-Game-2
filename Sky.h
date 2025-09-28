#ifndef SKY_H
#define SKY_H 

#include <iostream>

struct Sky
{
    std::string line {"                                        "};
    Sky* next {nullptr};

    const int lineSize {40};

    void setupLine(); //generate random objects within line
};

#endif