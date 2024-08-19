#ifndef StandardKeyboardService_H
#define StandardKeyboardService_H

#include "Key.h"
#include "KeyboardDisplay.h"
#include "Keyboard.h"
#include "UserInput.h"
#include "InputBlocking.h"

namespace keyboard {


class StandardKeyboardService {

public:
    StandardKeyboardService(Keyboard& keyboard);

    void displayKeyboard();

    void serveUserInteraction();

    void registerInputBlocking(InputBlocking* inputBlocking, int time);


private:
    void updateKeyDisplay(Key previousKey, Key currentKey);

    void inputBlockingService();

    void servePressedKey(Key key);

    Key previousKey;

    Keyboard& keyboard;

    InputBlocking* inputBlocking {nullptr};

    int time {0};

    UserInput* userInput = UserInput::getInstance();
};

}

#endif
