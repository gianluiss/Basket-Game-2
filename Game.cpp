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

}



//TOOL METHODS (Used within the class not outside):