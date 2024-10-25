#ifndef NotepadDisplay_H
#define NotepadDisplay_H

#include "DigitalLCD.h"
#include "Color.h"

namespace notepaddisplay {

/**
 * Clears the screen.
 * Draw rows of text on the screen.
 * @param rows the rows to draw.
 * @param rowsQuantity the number of rows to draw.
 */
void drawRows(std::string* rows, int rowsQuantity);

};


#endif