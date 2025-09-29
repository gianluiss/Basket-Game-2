#include "Game.h"

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

// Moves sky down or adds line & deletes out of bounds node
// updates score
// checks collision
// update basket state if moved or not
void Game::update()
{
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
   if(m_tail->line[m_basket.getPosition()] == '.') m_score -= 10;
}

void Game::handleInput()
{
    char input{};
    std::cin >> input;

    if(input == 'd') m_basket.moveRight();
    else if(input == 'a') m_basket.moveLeft();
    else if(input == 'q') m_running = false;

    return;
}