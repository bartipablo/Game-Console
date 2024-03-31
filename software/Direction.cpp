#include "Direction.h"

Direction nextDirection(Direction currentDirection) {
    switch(currentDirection) {
        case Direction::Up:
            return Direction::Right;
        case Direction::Down:
            return Direction::Left;
        case Direction::Left:
            return Direction::Up;
        case Direction::Right:
            return Direction::Down;
        default:
            return currentDirection;
    }
}

Direction previousDirection(Direction currentDirection) {
    switch(currentDirection) {
        case Direction::Up:
            return Direction::Left;
        case Direction::Left:
            return Direction::Down;
        case Direction::Down:
            return Direction::Right;
        case Direction::Right:
            return Direction::Up;
        default:
            return currentDirection;
    }
}
