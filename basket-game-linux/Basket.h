#ifndef BASKET_H
#define BASKET_H

class Basket
{
private:
    int m_position {};
    const int m_border {};
public:
    Basket(int position, const int border) : m_position{position}, m_border{border} {}

    void moveLeft() { if(m_position > 0) m_position--; }
    void moveRight() { if(m_position < m_border) m_position++; }
    int getPosition() const { return m_position; }
};

#endif