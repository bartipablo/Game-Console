#ifndef StandardKeyboardService_H
#define StandardKeyboardService_H

#include "Key.h"
#include "KeyboardDisplay.h"
#include "Keyboard.h"

class StandardKeyboardService {

public:
    StandardKeyboardService(Keyboard* keyboard, KeyboardDisplay* keyboardDisplay);

    void displayKeyboard();

    void serveUserInteraction();


private:
    void updateKeyDisplay(Key previousKey, Key currentKey);

    void servePressedKey(Key key);

    Key previousKey;

    Keyboard* keyboard;

    KeyboardDisplay* keyboardDisplay;
};


#endif
