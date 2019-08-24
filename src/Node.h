#ifndef NODE_H
#define NODE_H

#include <SFML/Graphics.hpp>

struct Node
{
    virtual ~Node() {}
    virtual void processEvent(sf::Event& e) = 0;
    virtual void updateState()              = 0;
    virtual void draw()                     = 0;
};

#endif
