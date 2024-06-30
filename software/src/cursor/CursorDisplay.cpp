#include "CursorDisplay.h"

CursorDisplay::CursorDisplay(Cursor& cursor) : cursor(cursor) {}

void CursorDisplay::drawCursor() {    
    CursorShape cursorShape = cursor.getCursorShape();

    std::vector<Pixel> cursorPixels = cursorShape.getPixels();
    Vector2D cursorPosition = cursor.getPosition();

    for (Pixel pixel : cursorPixels) {
        Vector2D position = pixel.getPosition();
        display->drawPixel(cursorPosition.x() + position.x(), cursorPosition.y() + position.y(), pixel.getColor());
    }
}
