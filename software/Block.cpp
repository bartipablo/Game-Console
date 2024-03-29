#include "Arduino.h"
#include "Block.h"

int Block::getColor() {
    return this->color;
}

Vector2D Block::getPosition() {
    return this->position;
}