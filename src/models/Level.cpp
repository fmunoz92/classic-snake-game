#include "Level.h"

#include <fstream>
#include <iostream>
#include <stdexcept>


Level::Level(const std::string& file, char id)
    : _patch("levels/level"),
      _ext(".txt"),
      _levelId(id),
      _maxFood('2'),
      _currentFood('2')
{
    loadMap(file);
}

Level::~Level()
{}

void Level::loadCell(char value, unsigned int x, unsigned int y)
{
    if (value == 's')
    {
        _initialPosSnake.push_back(Coord2(x, y));
        value = '0';
    }

    if (_maxFood < value && value < 's')
        _maxFood = value;

    _matrix[x][y] = value;
}

void Level::loadMap(const std::string& file)
{
    char value;
    std::ifstream input(file.c_str());

    if (!input)
    {
        std::cerr << "File Not Found: " << file << std::endl;
        throw std::exception();
    }

    for (unsigned int y = 0; y < HEIGHT; y++)
        for (unsigned int x = 0; x < WIDHT; x++)
        {
            input >> value;
            loadCell(value, x, y);
        }
}

char Level::getId() const
{
    return _levelId;
}

std::string Level::getPatch() const
{
    return _patch;
}

std::string Level::getExt() const
{
    return _ext;
}

const std::list<Coord2>& Level::getInitialPosSnake() const
{
    return _initialPosSnake;
}

Level::Content Level::whatHave(const Coord2& coor) const
{
    return whatHave(coor.x, coor.y);
}

Level::Content Level::whatHave(unsigned int x, unsigned  int y) const
{
    Content content;
    char value = _matrix[x][y];

    if (value == '1')
        content = Wall;
    else if (value == _currentFood)
        content = Food;
    else
        content = Nothing;

    return content;
}

bool Level::isDone() const
{
    return _currentFood > _maxFood;
}

void Level::consumeFood(const Coord2& coor)
{
    _currentFood = ++(_matrix[coor.x][coor.y]);
    _matrix[coor.x][coor.y] = '0';
}
