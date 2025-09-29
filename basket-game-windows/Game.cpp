#include "Game.h"
#include "ncurses.h"

void Game::initializeSky()
{
    Sky* current = m_head;
    for(int i = 0; i < m_skySize; i++)
    {
        if(m_head == nullptr)
        {
            m_head = new Sky;
            current = m_head;
            current->next = nullptr;
        }
        else
        {
            Sky* newPtr = new Sky;
            newPtr->next = nullptr;
            current->next = newPtr;
            current = current->next;
        }
    }
    m_tail = current;
}

//ncurses version
void Game::render() const
{
    if(!m_head)
    {
        printw("Error. Head is null\n");
        return;
    }
    
    Sky* current = m_head;
    printw("------------- Falling Money --------------\n");
    while(current != nullptr)
    {
        //Replace tail->line with basket position
        if(current == m_tail)
        {
            std::string basketLine = m_tail->line;
            basketLine[m_basket.getPosition()] = 'U';
            //std::cout << "|" << basketLine << "|\n";
            printw("|%s|\n", basketLine.c_str());
        }
        else
            printw("|%s|\n", current->line.c_str());
            //std::cout << "|" << current->line << "|\n";

        current = current->next;
    }
    //std::cout << "Your Score: " << m_score << '\n';
    printw("Your Score: %d\n", m_score);
}

/*
Initial version without the ncurses
void Game::render() const
{
    if(!m_head)
    {
        std::cerr << "Error. Head is null\n";
        return;
    }
    
    Sky* current = m_head;
    std::cout << "------------- Falling Money --------------\n";
    while(current != nullptr)
    {
        //Replace tail->line with basket position
        if(current == m_tail)
        {
            std::string basketLine = m_tail->line;
            basketLine[m_basket.getPosition()] = 'U';
            std::cout << "|" << basketLine << "|\n";
        }
        else
            std::cout << "|" << current->line << "|\n";

        current = current->next;
    }
    std::cout << "Your Score: " << m_score << '\n';

    //for debug 
    //might use this for video explanation
    //std::cout << m_tail->line[m_basket.getPosition()] << '\n';
}
*/

// Moves sky down or adds line & deletes out of bounds node
// updates score
// checks collision
// update basket state if moved or not
void Game::update()
{
    if(m_score >= m_maxScore || m_score <= 0) 
        m_running = false;

    if(!m_head)
    {
        std::cerr << "Error. Head is null\n";
        return;
    }

    if(!m_tail)
    {
        std::cerr << "Error. Tail is null\n";
        return;
    }

    //Move sky down or add sky
    Sky* newSky = new Sky;
    newSky->setupLine();
    newSky->next = m_head;
    m_head = newSky;

    // find previous tail node and delete tail
    Sky* current = m_head;
    while(true)
    {
        if( (current->next)->next == nullptr)
        {
            delete m_tail;
            m_tail = current;
            current->next = nullptr;
            break;
        }
        current = current->next;
    }

    /*
    Plan for basket collisions:
        - Check if there's an object with the position of the basket in m_tail->line
    */
   //might use this line for explanation
   //std::cout << "Object in basket: " << m_tail->line[m_basket.getPosition()] << '\n';
   if(m_tail->line[m_basket.getPosition()] == '$') m_score += 10;
   if(m_tail->line[m_basket.getPosition()] == '.') m_score -= 15;
}

//ncurses version
void Game::handleInput(int input)
{
    /*
    if(input == 'd') m_basket.moveRight();
    else if(input == 'a') m_basket.moveLeft();
    else if(input == 'q') m_running = false;
    */
    switch(input)
    {
        case 'q':
            m_running = false;
            break;
        case KEY_RIGHT:
            m_basket.moveRight();
            break;
        case KEY_LEFT:
            m_basket.moveLeft();
            break;
        default:
            break;
    }
    return;
}