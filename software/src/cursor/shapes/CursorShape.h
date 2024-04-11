#ifndef CursorShape_H
#define CursorShape_H

#include <vector>

#include "../../Pixel.h"

class CursorShape {

public:
    std::vector<Pixel> getPixels() {
        return pixels;
    }

protected:
    std::vector<Pixel> pixels;
};


#endif