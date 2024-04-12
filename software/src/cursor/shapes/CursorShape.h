#ifndef CursorShape_H
#define CursorShape_H

#include <vector>

#include "../../common/Pixel.h"

/**
 * Represents a cursor shape.
 * For example a cursor shape could be a Windows arrow.
 * The cursor shape is represented by a vector of pixels.
 * A pixel of shape does not correspond to one pixel on the screen. A lower resolution is used.
*/
class CursorShape {

public:
/**
 * @return the vector of pixels representing the cursor shape.
*/
    std::vector<Pixel> getPixels() {
        return pixels;
    }

/**
 * @return the height (in pixel) of each pixel in the cursor shape.
 */
    int getHeightPx() {
        return heightPx;
    }

/**
 * @return the width (in pixel) of each pixel in the cursor shape.
 */
    int getWidthPx() {
        return widthPx;
    }

protected:
    int heightPx; 

    int widthPx;

    std::vector<Pixel> pixels;
};


#endif