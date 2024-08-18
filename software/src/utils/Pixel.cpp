#include "Pixel.h"

Pixel::Pixel() : position {0, 0}, color {0} {}


Pixel::Pixel(Vector2D initPosition, int initColor) : position {initPosition}, color {initColor} {}


Vector2D Pixel::getPosition() const {
    return position;
}


int Pixel::getColor() const {
    return color;
}