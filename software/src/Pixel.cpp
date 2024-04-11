#include "Pixel.h"

Pixel::Pixel(Vector2D initPosition, int initColor) {
    position = initPosition;
    color = initColor;
}

Vector2D Pixel::getPosition() {
    return position;
}

int Pixel::getColor() {
    return color;
}