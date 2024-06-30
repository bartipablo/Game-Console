#include "StandardKeyboardService.h"

StandardKeyboardService::StandardKeyboardService(Keyboard* keyboard, KeyboardDisplay* keyboardDisplay) {
    this->keyboard = keyboard;
    this->keyboardDisplay = keyboardDisplay;
}


StandardKeyboardService::displayKeyboard() {
    keyboardDisplay->drawKeys(keyboard->getKeys());
    keyboardDisplay->drawSelectedKey(keyboard->getCurrentKey());
}


StandardKeyboardService::serveUserInteraction() {
    Key previousKey = keyboard->getCurrentKey();

    if (userInput->isPressedJoysticUp()) {
        keyboard->cursorUp();
        updateKeyDisplay(previousKey, keyboard->getCurrentKey());
    }
    else if (userInput->isPressedJoysticDown()) {
        keyboard->cursorDown();
        updateKeyDisplay(previousKey, keyboard->getCurrentKey());
    }
    else if (userInput->isPressedJoysticLeft()) {
        keyboard->cursorLeft();
        updateKeyDisplay(previousKey, keyboard->getCurrentKey());
    }
    else if (userInput->isPressedJoysticRight()) {
        keyboard->cursorRight();
        updateKeyDisplay(previousKey, keyboard->getCurrentKey());
    }
    else if (userInput->isPressedLeftButton()) {
        servePressedKey(keyboard->getCurrentKey());
    }
}


void StandardKeyboardService::updateKeyDisplay(Key previousKey, Key currentKey) {
    keyboardDisplay->drawKey(previousKey);
    keyboardDisplay->drawSelectedKey(currentKey);
    this->previousKey = currentKey;
}


void StandardKeyboardService::servePressedKey(Key key) {
    if (key.getCharacter() == CAPS_LOCK) {
        keyboard->changeKeySet();
        displayKeyboard();
    }
}
