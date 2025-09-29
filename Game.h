#ifndef GAME_H
#define GAME_H

#include "Sky.h"
#include "Basket.h"

class Game
{
private:
    Sky* m_head {nullptr};
    Sky* m_tail {nullptr};
    const int m_skySize {20}; //number of Sky nodes
    int m_score {50};

    // first value: basket position(m_position)
    // second value: border(m_border)
    Basket m_basket {19, 39}; 
    bool m_running {true};

public:
    // makes 20 nodes with blank sky
    // Asigns head and m_tail
    void initializeSky(); 
    void render() const;

    // Moves sky down or adds line & deletes out of bounds node
    // updates score
    // checks collision
    // update basket state if moved or not
    void update();
    void handleInput(int input); //ncurses version
    bool isRunning() const { return m_running; };
    
    int getScore() const { return m_score; }
};

#endif