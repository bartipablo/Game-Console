#ifndef NotepadEngine_H
#define NotepadEngine_H

#include "NotepadDisplay.h"
#include "Text.h"
#include "../keyboard/Keyboard.h"
#include "../keyboard/KeyboardDisplay.h"
#include "../keyboard/KeyboardFactory.h"
#include "../utils/InputBlocking.h"
#include "../utils/UserInput.h"

class NotepadEngine {

public:
    NotepadEngine();

    ~NotepadEngine();

/**
 * Starts the notepad application.
*/
    void run();

private:  
/**
 * Updates the key on the screen.
 * @param previousKey the previous key.
 * @param currentKey the current key.
*/
    void updateKey(Key previousKey, Key currentKey);

/**
 * Push-button operation.
 * @param key the key to serve.
 */
    void serveKey(Key key);

    bool shutdown;

    Text* text;

    Keyboard* keyboard;

    Keyboard

    NotepadDisplay* notepadDisplay;

    KeyboardDisplay* keyboardDisplay;

    InputBlocking* inputBlocking;

    UserInput* userInput = UserInput::getInstance();

};


#endif