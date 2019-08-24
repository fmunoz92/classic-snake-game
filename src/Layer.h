#ifndef LAYER_H
#define LAYER_H

#include "Node.h"

#include <SFML/Graphics.hpp>
#include <list>
#include <string>


class Layer : public Node
{
public:
    virtual ~Layer();

    virtual void addChild(Node* n);

    virtual void processEvent(sf::Event& e);
    virtual void updateState();
    virtual void draw();
protected:
    std::list<Node*> nodes;
};

#endif
