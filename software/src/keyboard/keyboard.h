#ifndef Keyboard_H
#define Keyboard_H

#include <map>
#include <vector>

#include "Key.h"
#include "KeySet.h"

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
    Keyboard(KeySet* standardKeySet);

    ~Keyboard();

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

    void initSpecialKeys();

    void addKeySet(KeySet* keySet);

    void changeKeySet();


private:
    Vector2D cursorPosition; /**< Position of the user cursor. */

    std::vector<KeySet*> keySets;

    KeySet* currentKeySet;

    Key backspace;

    Key capsLck;

    Key space;

    Key enter;
};

#endif