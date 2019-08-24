#include "FoodActor.h"

FoodActor::FoodActor()
{
    _director = Director::getInstance();

    _imgFood.loadFromFile("images/food.png");
    _spriteFood.setTexture(_imgFood);
}

void FoodActor::processEvent(sf::Event&)
{}

void FoodActor::updateState()
{}

void FoodActor::drawCell(unsigned int x, unsigned int y)
{
    Level* level = _director->getLevel();
    sf::RenderWindow* window = _director->getWindow();

    Level::Content content = level->whatHave(x, y);

    x *= Director::WIDHT_CELL;
    y *= Director::HEIGHT_CELL;

    if (content == Level::Food)
    {
        _spriteFood.setPosition(x, y);
        window->draw(_spriteFood);
    }
}

void FoodActor::draw()
{
    for (unsigned int y = 0; y < Level::HEIGHT; y++)
        for (unsigned int x = 0; x < Level::WIDHT; x++)
            drawCell(x, y);
}
