#include "CursorDisplay.h"

CursorDisplay::CursorDisplay(const Cursor& cursor) : cursor(cursor) {}

void CursorDisplay::drawCursor() {    
    CursorShape cursorShape = cursor.getCursorShape();

    std::vector<Pixel> cursorPixels = cursorShape.getPixels();
    Vector2D cursorPosition = cursor.getPosition();
    
    uint8_t originalRotation = display->getRotation();
    display->setRotation(3); 

    for (Pixel pixel : cursorPixels) {
        Vector2D position = pixel.getPosition();
        display->drawPixel(cursorPosition.x() + position.x(), cursorPosition.y() + position.y(), pixel.getColor());
    }

    display->setRotation(originalRotation);
}
