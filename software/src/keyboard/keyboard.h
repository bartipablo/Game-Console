#ifndef Keyboard_H
#define Keyboard_H

#include <map>
#include <vector>


#include "key.h"

/**
 * @brief Class representing keyboard.
 * 
 */
class Keyboard {

public:
    Keyboard();

    void cursorUp();

    void cursorDown();

    void cursorLeft();

    void cursorRight();

    Key getCurrentKey();

    std::vector<Key> getKeys();

private:
    bool isCapitalized; /**< Flag indicating if keyboard is capitalized. */

    Vector2D cursorPosition; /**< Position of the cursor. */

    Key lowercaseKeys[5][10]; /**< Array of lowercase keys. */

    Key capitalizeKeys[5][10]; /**< Array of capitalized keys. */

    Key backspace; /**< Backspace key. */

    Key space; /**< Space key. */

    Key enter; /**< Enter key. */

    void setCapitalized(bool isCapitalized);

    void initLowercaseKeys();

    void initCapitalizeKeys();

    void initSpecialKeys();


}
#endif