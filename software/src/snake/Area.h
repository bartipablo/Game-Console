#ifndef SnakeArea_H
#define SnakeArea_H

#include "../common/Vector2D.h"

namespace snake {

class Area {

public:
    bool isOutOfBound(Vector2D position) const;

    const static int WIDTH = 40;

    const static int HEIGHT = 40;
};

}

#endif