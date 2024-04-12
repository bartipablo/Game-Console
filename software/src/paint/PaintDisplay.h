#ifndef PaintDisplay_H
#define PaintDisplay_H

#include <vector>

#include "../utils/DigitalLCD.h"
#include "../common/Vector2D.h"
#include "Canvas.h"
#include "ColorBox.h"
#include "../common/Color.h"

class PaintDisplay {

public:
    PaintDisplay();

    void drawCanvas(Canvas& canvas);

    void drawCanvasPart(Canvas& canvas, Vector2D position, int widthPx, int heightPx);

    void drawColorBox(ColorBox& colorBox);

private:
    Arduino_ILI9341* display = DigitalLCD::getInstance();
};


#endif