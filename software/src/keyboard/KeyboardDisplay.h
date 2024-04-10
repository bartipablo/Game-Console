#ifndef KeyboardDisplay_H
#define KeyboardDisplay_H

#include "Keyboard.h"
#include "../DigitalLCD.h"

/**
 * @brief Class representing single key.
 * 
 */
class KeyboardDisplay {

public:
    KeyboardDisplay();

private:
    Arduino_ILI9341* display;
};


#endif