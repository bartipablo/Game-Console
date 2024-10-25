#ifndef Icon_H
#define Icon_H

#include "Vector2D.h"

class Icon {
public:
    Icon(Vector2D initPosition, int initWidth, int initHeight, int initPixelSize) 
    : position{initPosition}, width{initWidth}, height{initHeight}, pixelSize{initPixelSize} {}

    virtual ~Icon() = default;

/**
 * @return the width of the icon. (number of pixels in x-axis).
*/
    int getWidth() const {
        return width;
    }

/**
 * @return the height of the icon. (number of pixels in y-axis).
*/
    int getHeight() const {
        return height;
    }

/**
 * @return the size of a pixel in pixels.
 * For example, a pixelSize of 5 means that each pixel is 5x5 pixels.
 */
    int getPixelSize() const {
        return pixelSize;
    }

/**
 * @return the position of the icon on the screen.
 * The position is the top-left corner of the icon.
 */
    Vector2D getPosition() const {
        return position;
    }

/**
 * @param x the x-coordinate of the pixel.
 * @param y the y-coordinate of the pixel.
 * @return the RGB565 value of the pixel at the given coordinates.
 * NOTE: This method should work for ranges x = [0, width-1] and y = [0, height-1].
 */
    virtual int getRGB565(int x, int y) = 0;

protected:
    const Vector2D position;

    const int width;

    const int height;

    const int pixelSize;
};

#endif
