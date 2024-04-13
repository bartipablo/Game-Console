#ifndef Pixel_H
#define Pixel_H

#include "Vector2D.h"
#include "Color.h"

/**
 * @brief Class representing a pixel.
 * A pixel is represented by a position and a color.
 */
class Pixel {

public:
    Pixel();

    Pixel(Vector2D initPosition, int initColor);

/** Pixel position on LCD screen 320x240.
 *  @return the position of the pixel.
*/
    Vector2D getPosition();

    int getColor();
private:
    Vector2D position;

    int color;
};


#endif