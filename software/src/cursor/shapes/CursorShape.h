#ifndef CursorShape_H
#define CursorShape_H

#include <vector>

#include "../../Pixel.h"

/**
 * Represents a cursor shape.
 * For example a cursor shape could be a Windows arrow.
 * The cursor shape is represented by a vector of pixels.
*/
class CursorShape {

public:
    std::vector<Pixel> getPixels() {
        return pixels;
    }

    int getHeightPx() {
        return heightPx;
    }

    int getWidthPx() {
        return widthPx;
    }

protected:
    int heightPx;

    int widthPx;

    std::vector<Pixel> pixels;
};


#endif