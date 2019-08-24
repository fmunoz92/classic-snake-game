#include "Snake.h"

const Coord2 Snake::UP(0, -1);
const Coord2 Snake::DOWN(0, 1);
const Coord2 Snake::LEFT(-1, 0);
const Coord2 Snake::RIGHT(1, 0);

Snake::Snake(Level* level)
    : _isLive(true),
      _actualPos(4, 0),
      _nextPos(RIGHT),
      _level(level)
{
    reset();
}

void Snake::reset()
{
    const std::list<Coord2>& initialPos = _level->getInitialPosSnake();

    _cells.clear();
    _nextPos = _actualPos = RIGHT;

    for (std::list<Coord2>::const_iterator it = initialPos.begin(); it != initialPos.end(); it++)
        _cells.push_back(*it);
}

void Snake::internalMove(Coord2& nextCell)
{
    trans(nextCell);
    Level::Content content = _level->whatHave(nextCell);

    if (content == Level::Food)
        internalMoveWhitFood(nextCell);

    else if (content == Level::Wall)
        internalMoveWhitWall(nextCell);

    else// if (content == Level::Nothing)
        internalMoveWhitNothing(nextCell);
}

unsigned int Snake::length()
{
    return _cells.size();
}

void Snake::getCell(unsigned int pos, Coord2& res)
{
    res.x = _cells[pos].x;
    res.y = _cells[pos].y;
}

void Snake::internalMoveWhitFood(const Coord2& nextCell)
{
    _cells.push_back(nextCell);
    _level->consumeFood(nextCell);
}

void Snake::internalMoveWhitNothing(const Coord2& nextCell)
{
    for (unsigned int i = 0; i < _cells.size() - 1; i++)
        _cells[i] = _cells[i + 1];

    const unsigned int lastPos = _cells.size() - 1;
    _cells[lastPos] = nextCell;
}

void Snake::internalMoveWhitWall(const Coord2&)
{
    _isLive = false;
}

bool Snake::isLive()
{
    return _isLive;
}

bool Snake::autoCollision(const Coord2& nextCell)
{
    bool result = false;

    std::vector<Coord2>::const_iterator it = _cells.begin();

    while (it != _cells.end() && !result)
    {
        result = *it == nextCell;
        it++;
    }

    return result;
}

void Snake::trans(Coord2& nextCell)
{
    if (nextCell.x == int(Level::WIDHT))
        nextCell.x = 0;
    else if (nextCell.x == (-1))
        nextCell.x = Level::WIDHT - 1;
    else if (nextCell.y == int(Level::HEIGHT))
        nextCell.y = 0;
    else if (nextCell.y == (-1))
        nextCell.y = Level::HEIGHT - 1;
}

bool Snake::marchaAtras()
{
    bool marchaAtras = false;

    marchaAtras = marchaAtras || (_actualPos == RIGHT && _nextPos == LEFT);
    marchaAtras = marchaAtras || (_actualPos == LEFT  && _nextPos == RIGHT);
    marchaAtras = marchaAtras || (_actualPos == DOWN  && _nextPos == UP);
    marchaAtras = marchaAtras || (_actualPos == UP    && _nextPos == DOWN);

    return marchaAtras;
}

void Snake::move()
{
    bool mAtras = marchaAtras();

    Coord2 nextCell(_cells.back() + _nextPos);

    if (mAtras) //si hay marcha atras mantengo el movimiento :)
    {
        nextCell = _cells.back() + _actualPos;
        internalMove(nextCell);
    }
    else if ((_isLive = (_isLive && !autoCollision(nextCell))))
    {
        _actualPos = _nextPos;
        internalMove(nextCell);
    }
}

void Snake::changeDirection(const Coord2& newDir)
{
    _nextPos = newDir;
}

void Snake::setLevel(Level* level)
{
    _level = level;
}
