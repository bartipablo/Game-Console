#ifndef KeyboardFactory_H
#define KeyboardFactory_H

#include "Key.h"
#include "KeySet.h"
#include "keyboard.h"

namespace keyboard {

/**
 * @brief Class representing a keyboard factory.
 * It allows to create different types of keyboards.
 */
class KeyboardFactory {

public:
/**
 * @brief Create a classic keyboard.
 * The classic keyboard is represented in a QWERTY layout with several special characters.
 */
    static Keyboard createClassicKeyboard();

private:
    static KeySet generateLowerCaseLettersWithNumber();

    static KeySet generateUpperCaseLettersWithNumber();
};

}

#endif