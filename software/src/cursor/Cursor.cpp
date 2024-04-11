#include "Cursor.h"

Cursor::Cursor(CursorShape cursorShape) {
    position = Vector2D(0, 0);
    this->cursorShape = cursorShape;
}

Cursor::Cursor(CursorShape cursorShape, Vector2D initPosition) {
    position = initPosition;
    this->cursorShape = cursorShape;
}

Vector2D Cursor::getPosition() {
    return position;
}


// TO DO.
void Cursor::move(int xAnalogVal, int yAnalogVal) {
    return;
}

CursorShape Cursor::getCursorShape() {
    return cursorShape;
}