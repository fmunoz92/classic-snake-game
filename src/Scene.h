#ifndef SCENE_H
#define SCENE_H

#include "Layer.h"

struct Scene : public Layer
{
    virtual ~Scene() {}

    virtual void run();
    virtual void stop();
};

#endif
