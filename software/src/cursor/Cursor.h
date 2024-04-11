#ifndef Cursor_H
#define Cursor_H

#include <vector>

#include "../Vector2D.h"
#include "./shapes/CursorShape.h"
#include "../Pixel.h"

class Cursor {

public:
    Cursor(CursorShape cursorShape);

    Cursor(CursorShape cursorShape, Vector2D initPosition);

    Vector2D getPosition();

    CursorShape getCursorShape();

    void move(int xAnalogVal, int yAnalogVal);

private:
    Vector2D position;
    
    CursorShape cursorShape;
};


#endif