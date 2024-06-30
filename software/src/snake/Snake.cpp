#include "Snake.h"

namespace snake {

Snake::Snake(Vector2D initialPosition, Direction initialDirection) {
    head = initialPosition;
    tail = initialPosition;
    previousTail = initialPosition;

    body.push_back(initialPosition);
    direction = initialDirection;
}

void Snake::move() {
    previousTail = tail;
    Vector2D newHead;

    switch (direction) {
        case Direction::Up:
            newHead = Vector2D(head.x(), head.y() - 1);
            break;
        case Direction::Down:
            newHead = Vector2D(head.x(), head.y() + 1);
            break;
        case Direction::Left:
            newHead = Vector2D(head.x() - 1, head.y());
            break;
        case Direction::Right:
            newHead = Vector2D(head.x() + 1, head.y());
            break;
    }

    body.push_back(newHead);
    body.erase(body.begin());
    tail = body.front();

    head = newHead;
}

void Snake::grow() {
    if (tail == previousTail) {
        return;
    }

    body.insert(body.begin(), previousTail);
    tail = previousTail;
}

bool Snake::isCollidingWithItself() {
    int count = std::count(body.begin(), body.end(), head);

    if (count >= 2) {
        return true;
    }
    return false;
}

bool Snake::isAtPosition(Vector2D position) {
    return std::find(body.begin(), body.end(), position) != body.end();
}


void Snake::changeDirection(Direction newDirection) {
    if (direction == Direction::Up && newDirection == Direction::Down) {
        return;
    }

    if (direction == Direction::Down && newDirection == Direction::Up) {
        return;
    }

    if (direction == Direction::Left && newDirection == Direction::Right) {
        return;
    }

    if (direction == Direction::Right && newDirection == Direction::Left) {
        return;
    }

    direction = newDirection;
}

}