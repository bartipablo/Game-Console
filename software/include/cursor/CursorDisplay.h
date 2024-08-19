#ifndef CursorDisplay_H
#define CursorDisplay_H

#include <vector>

#include "DigitalLCD.h"
#include "CursorShape.h"
#include "Cursor.h"

namespace cursor {

void drawCursor(const Cursor& cursor);

}

#endif