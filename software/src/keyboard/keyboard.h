#ifndef Keyboard_H
#define Keyboard_H

#include <map>
#include <vector>

#include "Key.h"

/**
 * @brief Class representing keyboard.
 * The keyboard is represented in a QWERTY layout with several special characters.
 * 
 *  Coordinates representation:
 *  (0,0) → y
 *    ↓
 *    x
 */
class Keyboard {

public:
/**
 * @brief Construct a new Keyboard object.
 * This constructor initializes lowercaseKeys, capitalizeKeys and special keys.
*/
    Keyboard();

/**
 * @brief Move cursor up.
 * For example from key 'a' to key 'q'.
*/
    void cursorUp();

/**
 * @brief Move cursor down.
 * For example from key 'q' to key 'a'.
*/
    void cursorDown();

/**
 * @brief Move cursor left.
 * For example from key 's' to key 'a'.
 */
    void cursorLeft();

/**
 * @brief Move cursor right.
 * For example from key 's' to key 'd'.
 */
    void cursorRight();

/**
 * @brief Get the current key the user is pointing to
 */ 
    Key getCurrentKey();

/**
 * @brief Get all keys on the keyboard.
 */
    std::vector<Key> getKeys();

/**
 * @brief capitalize the keyboard.
 * @param capitalized - flag indicating if keyboard is capitalized.
 * If true, the keyboard will be capitalized.
 */
    void setCapitalized(bool capitalized);

/**
 * @brief Check if the keyboard is capitalized.
 * @return true if the keyboard is capitalized, false otherwise.
 */
    bool isCapitalized();

/**
 * @brief change the capitalization of the keyboard.
 * If the keyboard is capitalized, it will be changed to lowercase.
 * If the keyboard is lowercase, it will be changed to capitalized.
 */
    void changeCapitalization();

private:
    bool capitalized; /**< Flag indicating if keyboard is capitalized. */

    Vector2D cursorPosition; /**< Position of the user cursor. */

    Key lowercaseKeys[5][10]; /**< Array of lowercase keys. */

    Key capitalizeKeys[5][10]; /**< Array of capitalized keys. */

    Key backspace;

    Key capsLck;

    Key space;

    Key enter;

    void initLowercaseKeys();

    void initCapitalizeKeys();

    void initSpecialKeys();
};

#endif