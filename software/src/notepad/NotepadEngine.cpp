#include "NotepadEngine.h"

NotepadEngine::NotepadEngine() 
: text {new Text(53, 15)}, shutdown{false}, keyboard_{keyboard::KeyboardFactory::createClassicKeyboard()} {
}

NotepadEngine::~NotepadEngine() {
    delete text;
}

void NotepadEngine::run() {
    keyboard::StandardKeyboardService standardKeyboardService {keyboard_};

    standardKeyboardService.displayKeyboard();
    notepaddisplay::drawRows(text->getText(), text->getActualRow());
    inputBlocking.startBlocking(20);
    standardKeyboardService.registerInputBlocking(&inputBlocking, 10);

    while (!shutdown) {
        delay(20);

        if (!inputBlocking.isBlocked()) {
            
            standardKeyboardService.serveUserInteraction();

            if (userInput->isPressedLeftButton()) {
                serveKey(keyboard_.getCurrentKey());
            }
            else if (userInput->isPressedRightButton()) {
                return;
            }
        }
        inputBlocking.decrement();
    }
}

void NotepadEngine::serveKey(keyboard::Key key) {
    using keyboard::CAPS_LOCK;

    if (key.getCharacter() == CAPS_LOCK) {
        // ignore this case.
    }
    else if (key.getCharacter() == '\b') {
        text->backspace();
    }
    else {
        text->appendCharacter(key.getCharacter());
    }
    notepaddisplay::drawRows(text->getText(), text->getActualRow());
}