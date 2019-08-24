#include "Layer.h"

void Layer::addChild(Node* node)
{
    nodes.push_back(node);
}

void Layer::processEvent(sf::Event& e)
{
    for (std::list<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++)
        (*it)->processEvent(e);
}

void Layer::updateState()
{
    for (std::list<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++)
        (*it)->updateState();
}

void Layer::draw()
{
    for (std::list<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++)
        (*it)->draw();
}

Layer::~Layer()
{
    for (std::list<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++)
        delete *it;

}
