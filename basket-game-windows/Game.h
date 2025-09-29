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
    const int m_maxScore {100}; 
    Basket m_basket {19, 39}; //(m_position, m_border)
    bool m_running {true};

public:
    void initializeSky(); 
    void render() const;
    void update();
    void handleInput(char input);

    bool isRunning() const { return m_running; };
    int getScore() const { return m_score; }
    int getSkySize() const {return m_skySize; }
};

#endif
