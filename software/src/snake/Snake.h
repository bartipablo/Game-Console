#ifndef Snake_H
#define Snake_H

#include "../common/Vector2D.h"
#include "../common/Direction.h"

#include <vector>
#include <algorithm> 

namespace snake {

class Snake {

public:
    Snake(Vector2D initialPosition, Direction initialDirection);

    void move();

    void grow();

    bool isCollidingWithItself();

    bool isAtPosition(Vector2D position);

    void changeDirection(Direction newDirection);

    Vector2D getHeadPosition() {
        return head;
    }

    Vector2D getTailPosition() {
        return tail;
    }

    Vector2D getPreviousTailPosition() {
        return previousTail;
    }

    const static int SIZE = 6;

private:
    std::vector<Vector2D> body;

    Vector2D head;

    Vector2D tail;

    Vector2D previousTail;

    Direction direction;
};

}

#endif