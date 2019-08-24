#include "SnakeActor.h"

SnakeActor::SnakeActor()
{
    _director = Director::getInstance();

    _imgCellSnake.loadFromFile("images/snake.png");
    _spriteSnake.setTexture(_imgCellSnake);
}

void SnakeActor::processEvent(sf::Event& e)
{
    if (e.type == sf::Event::KeyPressed)
        processKeyPressed(e);
}

void SnakeActor::processKeyPressed(sf::Event& e)
{
    Snake* snake  = _director->getSnake();

    switch (e.key.code)
    {
        case sf::Keyboard::A :
        case sf::Keyboard::Left :
            snake->changeDirection(Snake::LEFT);
            break;

        case sf::Keyboard::D :
        case sf::Keyboard::Right :
            snake->changeDirection(Snake::RIGHT);
            break;

        case sf::Keyboard::W :
        case sf::Keyboard::Up :
            snake->changeDirection(Snake::UP);
            break;

        case sf::Keyboard::S :
        case sf::Keyboard::Down :
            snake->changeDirection(Snake::DOWN);
            break;

        default:
            break;
    }
}

void SnakeActor::updateState()
{
    sf::Time updateTime   = sf::seconds(0.2f);
    Snake* snake = _director->getSnake();
    sf::Clock* clock = _director->getClock();

    if (clock->getElapsedTime() > updateTime)
    {
        clock->restart(); // TODO: move this logic
        snake->move();
    }
}

void SnakeActor::draw()
{
    Coord2 pos;
    Snake* snake = _director->getSnake();

    for (unsigned int i = 0; i < snake->length(); i++)
    {
        snake->getCell(i, pos);
        drawCell(pos.x, pos.y);
    }
}

void SnakeActor::drawCell(unsigned int x, unsigned int y)
{
    x *= Director::WIDHT_CELL;
    y *= Director::HEIGHT_CELL;

    _spriteSnake.setPosition(x, y);
    _director->getWindow()->draw(_spriteSnake);
}
