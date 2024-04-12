#ifndef NotepadEngine_H
#define NotepadEngine_H

#include "NotepadDisplay.h"
#include "Text.h"
#include "../keyboard/Keyboard.h"
#include "../keyboard/KeyboardDisplay.h"
#include "../utils/InputBlocking.h"
#include "../utils/UserInput.h"

class NotepadEngine {

public:
    NotepadEngine();

    ~NotepadEngine();

    void run();

private:
    bool shutdown;

    Text* text;

    Keyboard* keyboard;

    NotepadDisplay* notepadDisplay;

    KeyboardDisplay* keyboardDisplay;

    InputBlocking* inputBlocking;

    UserInput* userInput = UserInput::getInstance();

    void updateKey(Key previousKey, Key currentKey);

    void serveKey(Key key);
};


#endif