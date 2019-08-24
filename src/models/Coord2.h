#ifndef COORD_2_H
#define COORD_2_H

struct Coord2
{
    Coord2();
    Coord2(int x, int y);

    Coord2 operator+(const Coord2& c) const;
    bool operator==(const Coord2& c) const;

    int x;
    int y;
};

#endif
