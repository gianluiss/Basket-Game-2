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
            return;
        }
        current = current->next;
    }

    //Handle basket here

    //Handle basket collisions
    /*
    Plan for basket collisions:
    - Have the basket have a separate copy of node
    - Show basket node instead of tail node
    - Compare the current position of the basket to the tail line
    */
}



//TOOL METHODS (Used within the class not outside):