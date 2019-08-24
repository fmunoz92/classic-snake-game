#ifndef FOOD_ACTOR_H
#define FOOD_ACTOR_H

#include "../Actor.h"
#include "../Director.h"

class FoodActor : public Actor
{
public:
    FoodActor();
    ~FoodActor() {}
private:
    virtual void processEvent(sf::Event& e);
    virtual void updateState();
    virtual void draw();

    void drawCell(unsigned int x, unsigned int y);

    Director* _director;

    sf::Sprite _spriteFood;
    sf::Texture _imgFood;
};

#endif
