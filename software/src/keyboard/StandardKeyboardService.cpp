#include "StandardKeyboardService.h"

namespace keyboard {

StandardKeyboardService::StandardKeyboardService(Keyboard& keyboard)
: keyboard{keyboard} {}


void StandardKeyboardService::displayKeyboard() {
    keyboarddisplay::drawKeys(keyboard.getKeys());
    keyboarddisplay::drawSelectedKey(keyboard.getCurrentKey());
}


void StandardKeyboardService::serveUserInteraction() {
    Key previousKey = keyboard.getCurrentKey();

    if (userInput->isPressedJoysticUp()) {
        keyboard.cursorUp();
        updateKeyDisplay(previousKey, keyboard.getCurrentKey());
        inputBlockingService();
    }
    else if (userInput->isPressedJoysticDown()) {
        keyboard.cursorDown();
        updateKeyDisplay(previousKey, keyboard.getCurrentKey());
        inputBlockingService();
    }
    else if (userInput->isPressedJoysticLeft()) {
        keyboard.cursorLeft();
        updateKeyDisplay(previousKey, keyboard.getCurrentKey());
        inputBlockingService();
    }
    else if (userInput->isPressedJoysticRight()) {
        keyboard.cursorRight();
        updateKeyDisplay(previousKey, keyboard.getCurrentKey());
        inputBlockingService();
    }
    else if (userInput->isPressedLeftButton()) {
        servePressedKey(keyboard.getCurrentKey());
        inputBlockingService();
    }
}


void StandardKeyboardService::updateKeyDisplay(Key previousKey, Key currentKey) {
    keyboarddisplay::drawKey(previousKey);
    keyboarddisplay::drawSelectedKey(currentKey);
    this->previousKey = currentKey;
}


void StandardKeyboardService::servePressedKey(Key key) {
    if (key.getCharacter() == CAPS_LOCK) {
        keyboard.changeKeySet();
        displayKeyboard();
    }
}


void StandardKeyboardService::registerInputBlocking(InputBlocking* inputBlocking, int time) {
    this->inputBlocking = inputBlocking;
    if (time < 0) {
        time = 0;
    }
    this->time = time;
}


void StandardKeyboardService::inputBlockingService() {
    if (inputBlocking == nullptr) {
        return;
    }
    inputBlocking->startBlocking(time);
}

}