#ifndef NotepadEngine_H
#define NotepadEngine_H

#include "NotepadDisplay.h"
#include "Text.h"
#include "Keyboard.h"
#include "KeyboardDisplay.h"
#include "KeyboardFactory.h"
#include "StandardKeyboardService.h"
#include "InputBlocking.h"
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