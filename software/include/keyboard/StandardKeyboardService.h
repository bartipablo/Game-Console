#ifndef StandardKeyboardService_H
#define StandardKeyboardService_H

#include "Key.h"
#include "KeyboardDisplay.h"
#include "Keyboard.h"
#include "UserInput.h"
#include "InputBlocking.h"

class StandardKeyboardService {

public:
    StandardKeyboardService(Keyboard* keyboard, KeyboardDisplay* keyboardDisplay);

    void displayKeyboard();

    void serveUserInteraction();

    void registerInputBlocking(InputBlocking* inputBlocking, int time);


private:
    void updateKeyDisplay(Key previousKey, Key currentKey);

    void inputBlockingService();

    void servePressedKey(Key key);

    Key previousKey;

    Keyboard* keyboard;

    KeyboardDisplay* keyboardDisplay;

    InputBlocking* inputBlocking = nullptr;

    int time = 0;

    UserInput* userInput = UserInput::getInstance();
};


#endif
