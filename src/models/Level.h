#ifndef LEVEL_H
#define LEVEL_H

#include "Coord2.h"
#include <list>
#include <string>


class Level
{
public:

    Level(const std::string& file, char id);
    ~Level();

    enum Content
    {
        Food,
        Wall,
        Nothing
    };

    static const unsigned int HEIGHT = 15;
    static const unsigned int WIDHT = 15;

    Content whatHave(const Coord2& coor) const;
    Content whatHave(unsigned int x, unsigned int y) const;
    void consumeFood(const Coord2& coor);
    bool isDone() const;
    char getId() const;

    std::string getPatch() const;//deberian ser estaticas
    std::string getExt() const;

    const std::list<Coord2>& getInitialPosSnake() const;

private:
    void loadMap(const std::string& file);
    void loadCell(char value, unsigned int x, unsigned int y);

    const std::string _patch;//deberian ser estaticas
    const std::string _ext;

    const char _levelId;

    std::list<Coord2> _initialPosSnake;
    char _maxFood;
    char _currentFood;
    char _matrix[WIDHT][HEIGHT];
};

#endif
