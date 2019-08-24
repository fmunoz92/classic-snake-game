#ifndef LEVEL_LAYER_H
#define LEVEL_LAYER_H

#include <SFML/Graphics.hpp>
#include "../Layer.h"

struct LevelLayer : public Layer
{
    LevelLayer() {}
    virtual ~LevelLayer() {}
    virtual void updateState();
};

#endif
