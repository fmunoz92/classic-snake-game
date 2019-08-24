#include "LevelLayer.h"
#include "../Director.h"

void LevelLayer::updateState()
{
    Layer::updateState();

    Director* director = Director::getInstance();
    Level* level = director->getLevel();

    if (level->isDone())
        director->goToNextLevel();
}
