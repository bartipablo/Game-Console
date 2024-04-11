#ifndef PaintDisplay_H
#define PaintDisplay_H

#include <vector>

#include "../DigitalLCD.h"
#include "../Vector2D.h"
#include "Canvas.h"

class PaintDisplay {

public:
    PaintDisplay();

    void drawCanvas(Canvas& canvas);

    void drawCanvasPart(Canvas& canvas, Vector2D position, int widthPx, int heightPx);

private:
    Arduino_ILI9341* display = DigitalLCD::getInstance();
};


#endif