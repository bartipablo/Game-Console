#ifndef Pixel_H
#define Pixel_H

#include "Vector2D.h"
#include "Color.h"

class Pixel {

public:
    Pixel(Vector2D initPosition, int initColor);

    Vector2D getPosition();

    int getColor();
private:
    Vector2D position;

    int color;
};


#endif