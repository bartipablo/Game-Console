#ifndef Canvas_H
#define Canvas_H

#include "Vector2D.h"
#include "Color.h"


namespace paint {

/**
 * Represents the canvas on which it is drawn.
*/
class Canvas {

public:

    Canvas();

/**
 * @return the pixels of the canvas.
 * The pixels are represented by a matrix of integers.
 * Each integer represents a color.
 * The matrix is of size (width x height).
*/
    int* getPixels();

/**
 * @return the width of the canvas.
 * The width is the number of pixels in the x-axis.
*/
    int getWidth() const;

/**
 * @return the height of the canvas.
 * The height is the number of pixels in the y-axis.
 */
    int getHeight() const;

/**
 * @return the size of a pixel in pixels.
 * For example, a pixelSize of 5 means that each pixel is 5x5 pixels.
 */
    int getPixelSize() const;

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
    constexpr static int WIDTH {64};
    constexpr static int  HEIGHT {48};
    constexpr static int PIXEL_SIZE {5};

    int pixels[HEIGHT][WIDTH]; /// represents colors!


};

}

#endif