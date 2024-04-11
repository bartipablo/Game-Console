#include "Cursor.h"

Cursor::Cursor(CursorShape cursorShape) {
    position = Vector2D(0, 0);
    this->cursorShape = cursorShape;
    this->sensitivity = 30;
}

Cursor::Cursor(CursorShape cursorShape, Vector2D initPosition) {
    position = initPosition;
    this->cursorShape = cursorShape;
    this->sensitivity = 30;
}

Vector2D Cursor::getPosition() {
    return position;
}

void Cursor::setSensitive(int sensitivity) {
    if (sensitivity <= 0) {
        sensitivity = 1;
    }
    this->sensitivity = sensitivity;
}


void Cursor::move(int xAnalogVal, int yAnalogVal) {
    int xShift = 0;
    int yShift = 0;

    if (xAnalogVal < 100) {
        xShift = ((255 - xAnalogVal) / sensitivity);
    }
    else if (xAnalogVal > 130) {
        xShift = (xAnalogVal / sensitivity) * (-1);
    }

    if (yAnalogVal < 100) {
        yShift = ((255 - yAnalogVal) / sensitivity) * (-1);
    }
    else if (yAnalogVal > 130) {
        yShift = (yAnalogVal / sensitivity);
    }

    int xNewPosition = position.x() + xShift;
    int yNewPosition = position.y() + yShift;

    xNewPosition = std::max(xNewPosition, 0);
    xNewPosition = std::min(xNewPosition, DigitalLCD::X_BOUNDARY);

    yNewPosition = std::max(yNewPosition, 0);
    yNewPosition = std::min(yNewPosition, DigitalLCD::Y_BOUNDARY);

    position = Vector2D(xNewPosition, yNewPosition);
}

CursorShape Cursor::getCursorShape() {
    return cursorShape;
}