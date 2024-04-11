#ifndef Canvas_H
#define Canvas_H

#include "../Vector2D.h"
#include "../Color.h"

class Canvas {

public:
    Canvas();

    ~Canvas();

    int** getPixels();

    int getWidth();

    int getHeight();

    int getPixelSize();

    void drawPixel(Vector2D cursorPosition, int color);

    void clear();

private:
    // represents colors!
    int** pixels;

    const int width = 64;
    const int height = 48;
    const int pixelSize = 5;
};


#endif