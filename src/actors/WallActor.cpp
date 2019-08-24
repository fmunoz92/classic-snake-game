#include "WallActor.h"

WallActor::WallActor()
{
    _director = Director::getInstance();

    _imgCellWall.loadFromFile("images/wall.png");

    _spriteWall.setTexture(_imgCellWall);
}

void WallActor::processEvent(sf::Event&)
{}

void WallActor::updateState()
{}

void WallActor::drawCell(unsigned int x, unsigned int y)
{
    Level* level = _director->getLevel();
    sf::RenderWindow* window = _director->getWindow();

    Level::Content content = level->whatHave(x, y);

    x *= Director::WIDHT_CELL;
    y *= Director::HEIGHT_CELL;

    if (content == Level::Wall)
    {
        _spriteWall.setPosition(x, y);
        window->draw(_spriteWall);
    }
}

void WallActor::draw()
{
    for (unsigned int y = 0; y < Level::HEIGHT; y++)
        for (unsigned int x = 0; x < Level::WIDHT; x++)
            drawCell(x, y);
}
