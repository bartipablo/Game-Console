#include "NotepadEngine.h"

NotepadEngine::NotepadEngine() {
    text = new Text(53, 15);
    keyboardFactory = new KeyboardFactory();
    keyboard = keyboardFactory->createClassicKeyboard();
    notepadDisplay = new NotepadDisplay();
    keyboardDisplay = new KeyboardDisplay();
    inputBlocking = new InputBlocking();
    standardKeyboardService = new StandardKeyboardService(keyboard, keyboardDisplay);

    shutdown = false;
}

NotepadEngine::~NotepadEngine() {
    delete text;
    delete keyboardFactory;
    delete keyboard;
    delete notepadDisplay;
    delete keyboardDisplay;
    delete inputBlocking;
    delete standardKeyboardService;
}

void NotepadEngine::run() {
    standardKeyboardService->displayKeyboard();
    notepadDisplay->drawRows(text->getText(), text->getActualRow());
    inputBlocking->startBlocking(20);
    standardKeyboardService->registerInputBlocking(inputBlocking, 10);

    while (!shutdown) {
        delay(20);

        if (!inputBlocking->isBlocked()) {
            
            standardKeyboardService->serveUserInteraction();

            if (userInput->isPressedLeftButton()) {
                serveKey(keyboard->getCurrentKey());
            }
            else if (userInput->isPressedRightButton()) {
                return;
            }
        }
        inputBlocking->decrement();
    }
}

void NotepadEngine::serveKey(Key key) {
    if (key.getCharacter() == CAPS_LOCK) {
        // ignore this case.
    }
    else if (key.getCharacter() == '\b') {
        text->backspace();
    }
    else {
        text->appendCharacter(key.getCharacter());
    }
    notepadDisplay->drawRows(text->getText(), text->getActualRow());
}