#ifndef WALLACTOR_H
#define WALLACTOR_H

#include <SFML/Graphics.hpp>
#include "../Actor.h"
#include "../Director.h"

class WallActor : public Actor
{
public:
    WallActor();
    ~WallActor() {}

private:
    virtual void processEvent(sf::Event& e);
    virtual void updateState();
    virtual void draw();

    void drawCell(unsigned int x, unsigned int y);

    Director* _director;

    sf::Sprite _spriteWall;
    sf::Texture _imgCellWall;
};

#endif
