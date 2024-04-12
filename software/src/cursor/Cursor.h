#ifndef Cursor_H
#define Cursor_H

#include <vector>
#include <algorithm>

#include "../common/Vector2D.h"
#include "./shapes/CursorShape.h"
#include "../common/Pixel.h"
#include "../utils/DigitalLCD.h"

/**
 * @brief Class representing a user cursor.
 * For example a cursor could be a Windows arrow.
 * 
 */
class Cursor {

public:
    Cursor(CursorShape cursorShape);

    Cursor(CursorShape cursorShape, Vector2D initPosition);

/**
 * @brief Get the position to which the cursor is pointing.
*/
    Vector2D getPosition();

    CursorShape getCursorShape();

/**
 * @brief Move the cursor by a given x and y value.
 * Values should be transmitted via analogue joystick readout
*/
    void move(int xAnalogVal, int yAnalogVal);

/**
 * @brief Set the sensitivity of the cursor.
 * Values should be greater than 1.
 * The higher the value, the lower the sensitivity.
   The smaller the value, the higher the sensitivity.
*/
    void setSensitive(int sensitivity);

private:
    int sensitivity;

    Vector2D position;
    
    CursorShape cursorShape;
};


#endif