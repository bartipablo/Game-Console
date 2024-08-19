#include "KeyboardFactory.h"

namespace keyboard {

Keyboard KeyboardFactory::createClassicKeyboard() {
    KeySet lowercaseClassicKeysWithNumbers = generateLowerCaseLettersWithNumber();
    Keyboard keyboard {lowercaseClassicKeysWithNumbers};

    KeySet uppercaseClassicKeysWithNumbers = generateUpperCaseLettersWithNumber();
    keyboard.addKeySet(uppercaseClassicKeysWithNumbers);

    return keyboard;
}

KeySet KeyboardFactory::generateLowerCaseLettersWithNumber() {
    KeySet lowercaseClassicKeysWithNumbers {};

    lowercaseClassicKeysWithNumbers.setKey(0, 0, Key('1', Vector2D(0, 0), 1));
    lowercaseClassicKeysWithNumbers.setKey(0, 1, Key('2', Vector2D(0, 1), 1));
    lowercaseClassicKeysWithNumbers.setKey(0, 2, Key('3', Vector2D(0, 2), 1));
    lowercaseClassicKeysWithNumbers.setKey(0, 3, Key('4', Vector2D(0, 3), 1));
    lowercaseClassicKeysWithNumbers.setKey(0, 4, Key('5', Vector2D(0, 4), 1));
    lowercaseClassicKeysWithNumbers.setKey(0, 5, Key('6', Vector2D(0, 5), 1));
    lowercaseClassicKeysWithNumbers.setKey(0, 6, Key('7', Vector2D(0, 6), 1));
    lowercaseClassicKeysWithNumbers.setKey(0, 7, Key('8', Vector2D(0, 7), 1));
    lowercaseClassicKeysWithNumbers.setKey(0, 8, Key('9', Vector2D(0, 8), 1));
    lowercaseClassicKeysWithNumbers.setKey(0, 9, Key('0', Vector2D(0, 9), 1));

    lowercaseClassicKeysWithNumbers.setKey(1, 0, Key('q', Vector2D(1, 0), 1));
    lowercaseClassicKeysWithNumbers.setKey(1, 1, Key('w', Vector2D(1, 1), 1));
    lowercaseClassicKeysWithNumbers.setKey(1, 2, Key('e', Vector2D(1, 2), 1));
    lowercaseClassicKeysWithNumbers.setKey(1, 3, Key('r', Vector2D(1, 3), 1));
    lowercaseClassicKeysWithNumbers.setKey(1, 4, Key('t', Vector2D(1, 4), 1));
    lowercaseClassicKeysWithNumbers.setKey(1, 5, Key('y', Vector2D(1, 5), 1));
    lowercaseClassicKeysWithNumbers.setKey(1, 6, Key('u', Vector2D(1, 6), 1));
    lowercaseClassicKeysWithNumbers.setKey(1, 7, Key('i', Vector2D(1, 7), 1));
    lowercaseClassicKeysWithNumbers.setKey(1, 8, Key('o', Vector2D(1, 8), 1));
    lowercaseClassicKeysWithNumbers.setKey(1, 9, Key('p', Vector2D(1, 9), 1));

    lowercaseClassicKeysWithNumbers.setKey(2, 0, Key('a', Vector2D(2, 0), 1));
    lowercaseClassicKeysWithNumbers.setKey(2, 1, Key('s', Vector2D(2, 1), 1));
    lowercaseClassicKeysWithNumbers.setKey(2, 2, Key('d', Vector2D(2, 2), 1));
    lowercaseClassicKeysWithNumbers.setKey(2, 3, Key('f', Vector2D(2, 3), 1));
    lowercaseClassicKeysWithNumbers.setKey(2, 4, Key('g', Vector2D(2, 4), 1));
    lowercaseClassicKeysWithNumbers.setKey(2, 5, Key('h', Vector2D(2, 5), 1));
    lowercaseClassicKeysWithNumbers.setKey(2, 6, Key('j', Vector2D(2, 6), 1));
    lowercaseClassicKeysWithNumbers.setKey(2, 7, Key('k', Vector2D(2, 7), 1));
    lowercaseClassicKeysWithNumbers.setKey(2, 8, Key('l', Vector2D(2, 8), 1));
    lowercaseClassicKeysWithNumbers.setKey(2, 9, Key('!', Vector2D(2, 9), 1));
    
    lowercaseClassicKeysWithNumbers.setKey(3, 0, Key('z', Vector2D(3, 0), 1));
    lowercaseClassicKeysWithNumbers.setKey(3, 1, Key('x', Vector2D(3, 1), 1));
    lowercaseClassicKeysWithNumbers.setKey(3, 2, Key('c', Vector2D(3, 2), 1));
    lowercaseClassicKeysWithNumbers.setKey(3, 3, Key('v', Vector2D(3, 3), 1));
    lowercaseClassicKeysWithNumbers.setKey(3, 4, Key('b', Vector2D(3, 4), 1));
    lowercaseClassicKeysWithNumbers.setKey(3, 5, Key('n', Vector2D(3, 5), 1));
    lowercaseClassicKeysWithNumbers.setKey(3, 6, Key('m', Vector2D(3, 6), 1));
    lowercaseClassicKeysWithNumbers.setKey(3, 7, Key(',', Vector2D(3, 7), 1));
    lowercaseClassicKeysWithNumbers.setKey(3, 8, Key('.', Vector2D(3, 8), 1));
    lowercaseClassicKeysWithNumbers.setKey(3, 9, Key('?', Vector2D(3, 9), 1));

    return lowercaseClassicKeysWithNumbers;
}


KeySet KeyboardFactory::generateUpperCaseLettersWithNumber() {
    KeySet uppercaseClassicKeysWithNumbers {};

    uppercaseClassicKeysWithNumbers.setKey(0, 0, Key('1', Vector2D(0, 0), 1));
    uppercaseClassicKeysWithNumbers.setKey(0, 1, Key('2', Vector2D(0, 1), 1));
    uppercaseClassicKeysWithNumbers.setKey(0, 2, Key('3', Vector2D(0, 2), 1));
    uppercaseClassicKeysWithNumbers.setKey(0, 3, Key('4', Vector2D(0, 3), 1));
    uppercaseClassicKeysWithNumbers.setKey(0, 4, Key('5', Vector2D(0, 4), 1));
    uppercaseClassicKeysWithNumbers.setKey(0, 5, Key('6', Vector2D(0, 5), 1));
    uppercaseClassicKeysWithNumbers.setKey(0, 6, Key('7', Vector2D(0, 6), 1));
    uppercaseClassicKeysWithNumbers.setKey(0, 7, Key('8', Vector2D(0, 7), 1));
    uppercaseClassicKeysWithNumbers.setKey(0, 8, Key('9', Vector2D(0, 8), 1));
    uppercaseClassicKeysWithNumbers.setKey(0, 9, Key('0', Vector2D(0, 9), 1));

    uppercaseClassicKeysWithNumbers.setKey(1, 0, Key('Q', Vector2D(1, 0), 1));
    uppercaseClassicKeysWithNumbers.setKey(1, 1, Key('W', Vector2D(1, 1), 1));
    uppercaseClassicKeysWithNumbers.setKey(1, 2, Key('E', Vector2D(1, 2), 1));
    uppercaseClassicKeysWithNumbers.setKey(1, 3, Key('R', Vector2D(1, 3), 1));
    uppercaseClassicKeysWithNumbers.setKey(1, 4, Key('T', Vector2D(1, 4), 1));
    uppercaseClassicKeysWithNumbers.setKey(1, 5, Key('Y', Vector2D(1, 5), 1));
    uppercaseClassicKeysWithNumbers.setKey(1, 6, Key('U', Vector2D(1, 6), 1));
    uppercaseClassicKeysWithNumbers.setKey(1, 7, Key('I', Vector2D(1, 7), 1));
    uppercaseClassicKeysWithNumbers.setKey(1, 8, Key('O', Vector2D(1, 8), 1));
    uppercaseClassicKeysWithNumbers.setKey(1, 9, Key('P', Vector2D(1, 9), 1));

    uppercaseClassicKeysWithNumbers.setKey(2, 0, Key('A', Vector2D(2, 0), 1));
    uppercaseClassicKeysWithNumbers.setKey(2, 1, Key('S', Vector2D(2, 1), 1));
    uppercaseClassicKeysWithNumbers.setKey(2, 2, Key('D', Vector2D(2, 2), 1));
    uppercaseClassicKeysWithNumbers.setKey(2, 3, Key('F', Vector2D(2, 3), 1));
    uppercaseClassicKeysWithNumbers.setKey(2, 4, Key('G', Vector2D(2, 4), 1));
    uppercaseClassicKeysWithNumbers.setKey(2, 5, Key('H', Vector2D(2, 5), 1));
    uppercaseClassicKeysWithNumbers.setKey(2, 6, Key('J', Vector2D(2, 6), 1));
    uppercaseClassicKeysWithNumbers.setKey(2, 7, Key('K', Vector2D(2, 7), 1));
    uppercaseClassicKeysWithNumbers.setKey(2, 8, Key('L', Vector2D(2, 8), 1));
    uppercaseClassicKeysWithNumbers.setKey(2, 9, Key('!', Vector2D(2, 9), 1));
    
    uppercaseClassicKeysWithNumbers.setKey(3, 0, Key('Z', Vector2D(3, 0), 1));
    uppercaseClassicKeysWithNumbers.setKey(3, 1, Key('X', Vector2D(3, 1), 1));
    uppercaseClassicKeysWithNumbers.setKey(3, 2, Key('C', Vector2D(3, 2), 1));
    uppercaseClassicKeysWithNumbers.setKey(3, 3, Key('V', Vector2D(3, 3), 1));
    uppercaseClassicKeysWithNumbers.setKey(3, 4, Key('B', Vector2D(3, 4), 1));
    uppercaseClassicKeysWithNumbers.setKey(3, 5, Key('N', Vector2D(3, 5), 1));
    uppercaseClassicKeysWithNumbers.setKey(3, 6, Key('M', Vector2D(3, 6), 1));
    uppercaseClassicKeysWithNumbers.setKey(3, 7, Key('<', Vector2D(3, 7), 1));
    uppercaseClassicKeysWithNumbers.setKey(3, 8, Key('>', Vector2D(3, 8), 1));
    uppercaseClassicKeysWithNumbers.setKey(3, 9, Key('?', Vector2D(3, 9), 1));

    return uppercaseClassicKeysWithNumbers;
}

}