#ifndef PaintDisplay_H
#define PaintDisplay_H

#include <vector>

#include "DigitalLCD.h"
#include "Vector2D.h"
#include "Canvas.h"
#include "ColorBox.h"
#include "Color.h"

namespace paintdisplay {

/**
 * This method draws the whole canvas on the screen.
 * @brief Draw the canvas on the screen.
 * @param canvas the canvas to draw.
*/
void drawCanvas(paint::Canvas& canvas);

/**
 * This method draws a part of the canvas on the screen.
 * @brief Draw a part of the canvas on the screen.
 * @param canvas the canvas to draw.
 * @param position the position of the part to draw.
 * @param widthPx the width of the part to draw.
 * @param heightPx the height of the part to draw.
*/
void drawCanvasPart(paint::Canvas& canvas, Vector2D position, int widthPx, int heightPx);

/**
 * This method draws color boxes on the screen.
 * @brief Draw color boxes on the screen.
 * @param colorBoxes the color boxes to draw.
 */
void drawColorBox(paint::ColorBox& colorBox);
}


#endif