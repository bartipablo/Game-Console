#ifndef Icon_H
#define Icon_H

#include "../common/Vector2D.h"

class Icon {
public:
    int getWidth() {
        return width;
    }

    int getHeight() {
        return height;
    }

    int getPixelSize() {
        return pixelSize;
    }

    Vector2D getPosition() {
        return position;
    }

    virtual int getRGB565(int x, int y) = 0;

protected:
    Vector2D position;

    int width;

    int height;

    int pixelSize;
};

#endif
