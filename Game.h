#ifndef GAME_H
#define GAME_H

#include "Sky.h"

class Game
{
private:
    Sky* m_head {nullptr};
    Sky* m_tail {nullptr};
    //Basket 

    const int m_skySize {20};

    int m_score {};
public:
    // makes 20 nodes with blank sky
    //Asigns head and m_tail
    void initializeSky(); 
    void render() const;

    //Moves sky down or adds line & deletes out of bounds node
    //updates score
    //checks collision
    //update basket state if moved or not
    void update(); 

    //tools:
    bool isNull(Sky *node) const { return node == nullptr ? true : false; }
    Sky* getHead() const { return m_head; }
};

#endif