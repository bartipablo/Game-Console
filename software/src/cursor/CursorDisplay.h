#ifndef CursorDisplay_H
#define CursorDisplay_H

#include <vector>

#include "../DigitalLCD.h"
#include "./shapes/CursorShape.h"
#include "Cursor.h"

/**
 * @brief Class representing a cursor display.
 * It allows draw the cursor on the screen.
 * NOTE: the class does not provide a method to clear the cursor on the screen
 */
class CursorDisplay {

public:
    CursorDisplay(Cursor& cursor);

    void drawCursor();

private:
    Cursor& cursor;

    Arduino_ILI9341* display = DigitalLCD::getInstance();
};


#endif