#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

#include "Level.h"
#include "Coord2.h"

class Snake
{
public:
    Snake(Level* level);

    void move();
    void changeDirection(const Coord2& newDir);
    bool isLive();
    unsigned int length();
    void reset();

    void setLevel(Level* level);

    void getCell(unsigned int pos, Coord2& res);

    static const Coord2 UP;
    static const Coord2 DOWN;
    static const Coord2 LEFT;
    static const Coord2 RIGHT;

private:
    void internalMove(Coord2& nextCell);

    void internalMoveWhitNothing(const Coord2& nextCell);
    void internalMoveWhitFood(const Coord2& nextCell);
    void internalMoveWhitWall(const Coord2& nextCell);

    bool autoCollision(const Coord2& nextCell);
    bool marchaAtras();

    void trans(Coord2& nextCell);

    bool _isLive;
    std::vector<Coord2> _cells;
    Coord2 _actualPos;
    Coord2 _nextPos;
    Level* _level;
};

#endif
