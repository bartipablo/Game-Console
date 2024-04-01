#include "Block.h"


int Block::getColor() const {
    return this->color;
}

Vector2D Block::getPosition() const {
    return this->position;
}

void Block::updatePosition(const Vector2D newPosition) {
    position = newPosition;
}