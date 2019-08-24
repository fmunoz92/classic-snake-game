#ifndef TEXT_END_ACTOR_H
#define TEXT_END_ACTOR_H

#include <SFML/Graphics.hpp>
#include "../Actor.h"
#include "../Director.h"

class TextEndActor : public Actor
{
public:
    TextEndActor();
    virtual ~TextEndActor() {}
private:
    virtual void processEvent(sf::Event& e);
    virtual void updateState();
    virtual void draw();

    sf::Text _textEnd;
    sf::Font _cheeseburger;

    Director* _director;
};

#endif
