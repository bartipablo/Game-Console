#ifndef NotepadEngine_H
#define NotepadEngine_H

#include "NotepadDisplay.h"
#include "Text.h"
#include "../keyboard/Keyboard.h"
#include "../keyboard/KeyboardDisplay.h"
#include "../keyboard/KeyboardFactory.h"
#include "../keyboard/StandardKeyboardService.h"
#include "../utils/InputBlocking.h"
#include "UserInput.h"

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
 * Push-button operation.
 * @param key the key to serve.
 */
    void serveKey(Key key);

    bool shutdown;

    Text* text;

    Keyboard* keyboard;

    KeyboardFactory* keyboardFactory;

    NotepadDisplay* notepadDisplay;

    KeyboardDisplay* keyboardDisplay;

    StandardKeyboardService* standardKeyboardService;

    InputBlocking* inputBlocking;

    UserInput* userInput = UserInput::getInstance();

};


#endif