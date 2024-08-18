#ifndef Canvas_H
#define Canvas_H

#include "Vector2D.h"
#include "Color.h"

/**
 * Represents the canvas on which it is drawn.
*/
class Canvas {

public:

    Canvas();

    ~Canvas();

/**
 * @return the pixels of the canvas.
 * The pixels are represented by a matrix of integers.
 * Each integer represents a color.
 * The matrix is of size (width x height).
*/
    int** getPixels();

/**
 * @return the width of the canvas.
 * The width is the number of pixels in the x-axis.
*/
    int getWidth();

/**
 * @return the height of the canvas.
 * The height is the number of pixels in the y-axis.
 */
    int getHeight();

/**
 * @return the size of a pixel in pixels.
 * For example, a pixelSize of 5 means that each pixel is 5x5 pixels.
 */
    int getPixelSize();

/**
 * @param cursorPosition the position of the cursor.
 * @param color the color of the pixel.
 * Draw a pixel at the given position with the given color.
 */
    void drawPixel(Vector2D cursorPosition, int color);

/**
 * clears the canvas.
 * Sets all pixels to white.
 */
    void clear();

private:
    int** pixels; /// represents colors!

    const int width = 64;
    const int height = 48;
    const int pixelSize = 5;
};


#endif