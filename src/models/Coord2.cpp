#include "Coord2.h"

Coord2::Coord2(int x, int y)
    : x(x),
      y(y)
{}

Coord2::Coord2()
{}

Coord2 Coord2::operator +(const Coord2& c) const
{
    return Coord2(c.x + x, c.y + y);
}

bool Coord2::operator ==(const Coord2& c) const
{
    return (x == c.x) && (y == c.y);
}
