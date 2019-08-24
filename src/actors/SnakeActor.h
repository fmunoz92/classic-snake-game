#ifndef SNAKE_ACTOR_H
#define SNAKE_ACTOR_H

#include <SFML/Graphics.hpp>
#include "../Actor.h"
#include "../Director.h"

class SnakeActor : public Actor
{
public:
    SnakeActor();
    virtual ~SnakeActor() {}
private:
    virtual void processEvent(sf::Event& e);
    virtual void updateState();
    virtual void draw();

    void processKeyPressed(sf::Event& e);

    void drawCell(unsigned int x, unsigned int y);

    Director* _director;

    sf::Texture _imgCellSnake;
    sf::Sprite _spriteSnake;
};

#endif
