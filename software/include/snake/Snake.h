#ifndef Snake_H
#define Snake_H

#include "Vector2D.h"
#include "Direction.h"

#include <vector>
#include <algorithm> 

namespace snake {

/**
 * Represents the snake that the player controls.
 */
class Snake {

public:
    Snake(Vector2D initialPosition, Direction initialDirection);

/**
 * Moves the snake one step forward.
 */
    void move();

/**
 * Grows the snake by one unit.
 */
    void grow();

/**
 * Checks if the snake is colliding with itself.
 */
    bool isCollidingWithItself();

/**
 * Checks if the snake is at the given position.
 */
    bool isAtPosition(Vector2D position);

/**
 * Changes the direction of the snake if the new direction is not the opposite of the current direction.
 */
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

    std::vector<Vector2D> getBodyPositions() {
        return body;
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