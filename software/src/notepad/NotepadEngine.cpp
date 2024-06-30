#include "NotepadEngine.h"

NotepadEngine::NotepadEngine() {
    text = new Text(53, 15);
    keyboardFactory = new KeyboardFactory();
    keyboard = keyboardFactory->createClassicKeyboard();
    notepadDisplay = new NotepadDisplay();
    keyboardDisplay = new KeyboardDisplay();
    inputBlocking = new InputBlocking();

    shutdown = false;
}

NotepadEngine::~NotepadEngine() {
    delete text;
    delete keyboardFactory;
    delete keyboard;
    delete notepadDisplay;
    delete keyboardDisplay;
    delete inputBlocking;
}

void NotepadEngine::run() {
    keyboardDisplay->drawKeys(keyboard->getKeys());
    keyboardDisplay->drawSelectedKey(keyboard->getCurrentKey());
    notepadDisplay->drawRows(text->getText(), text->getActualRow());
    inputBlocking->startBlocking(20);

    while (!shutdown) {
        delay(20);

        if (!inputBlocking->isBlocked()) {

            Key previousKey = keyboard->getCurrentKey();

            if (userInput->isPressedJoysticUp()) {
                keyboard->cursorUp();
                updateKey(previousKey, keyboard->getCurrentKey());
            }
            else if (userInput->isPressedJoysticDown()) {
                keyboard->cursorDown();
                updateKey(previousKey, keyboard->getCurrentKey());
            }
            else if (userInput->isPressedJoysticLeft()) {
                keyboard->cursorLeft();
                updateKey(previousKey, keyboard->getCurrentKey());
            }
            else if (userInput->isPressedJoysticRight()) {
                keyboard->cursorRight();
                updateKey(previousKey, keyboard->getCurrentKey());
            }
            else if (userInput->isPressedLeftButton()) {
                serveKey(keyboard->getCurrentKey());
            }
            else if (userInput->isPressedRightButton()) {
                return;
            }
        }
        inputBlocking->decrement();
    }
}

void NotepadEngine::updateKey(Key previousKey, Key currentKey) {
    keyboardDisplay->drawKey(previousKey);
    keyboardDisplay->drawSelectedKey(currentKey);
    inputBlocking->startBlocking(10);
}

void NotepadEngine::serveKey(Key key) {
    if (key.getCharacter() == 7) {
        keyboard->changeCapitalization();
        keyboardDisplay->drawKeys(keyboard->getKeys());
        keyboardDisplay->drawSelectedKey(keyboard->getCurrentKey());
    }
    else if (key.getCharacter() == '\b') {
        text->backspace();
    }
    else {
        text->appendCharacter(key.getCharacter());
    }
    inputBlocking->startBlocking(10);
    notepadDisplay->drawRows(text->getText(), text->getActualRow());
}