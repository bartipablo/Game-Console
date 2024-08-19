#ifndef SnakeArea_H
#define SnakeArea_H

#include "Vector2D.h"

namespace snake {

/**
 * Represents the area where the snake can move.
 */
class Area {

public:
/**
 * Checks if the given position is out of the area.
 * @return true if the position is out of the area, false otherwise.
 */
    bool isOutOfBound(Vector2D position) const;

    const static int WIDTH = 40;

    const static int HEIGHT = 40;
};

}

#endif