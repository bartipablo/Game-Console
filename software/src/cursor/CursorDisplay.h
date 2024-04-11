#ifndef CursorDisplay_H
#define CursorDisplay_H

#include <vector>

#include "../DigitalLCD.h"
#include "./shapes/CursorShape.h"
#include "Cursor.h"

class CursorDisplay {

public:
    CursorDisplay(const Cursor& cursor);

    void drawCursor();

private:
    Cursor cursor;

    Arduino_ILI9341* display = DigitalLCD::getInstance();
};


#endif