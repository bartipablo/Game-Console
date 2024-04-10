#include "Keyboard.h"

Keyboard::Keyboard() {
    initLowercaseKeys();
    initCapitalizeKeys();
    initSpecialKeys();
}

void Keyboard::setCapitalized(bool isCapitalized) {
    this->isCapitalized = isCapitalized;
}

void Keyboard::initLowercaseKeys() {
    lowercaseKeys[0][0] = Key('1', Vector2D(0, 0), 1);
    lowercaseKeys[0][1] = Key('2', Vector2D(0, 1), 1);
    lowercaseKeys[0][2] = Key('3', Vector2D(0, 2), 1);
    lowercaseKeys[0][3] = Key('4', Vector2D(0, 3), 1);
    lowercaseKeys[0][4] = Key('5', Vector2D(0, 4), 1);
    lowercaseKeys[0][5] = Key('6', Vector2D(0, 5), 1);
    lowercaseKeys[0][6] = Key('7', Vector2D(0, 6), 1);
    lowercaseKeys[0][7] = Key('8', Vector2D(0, 7), 1);
    lowercaseKeys[0][8] = Key('9', Vector2D(0, 8), 1);
    lowercaseKeys[0][9] = Key('0', Vector2D(0, 9), 1);

    lowercaseKeys[1][0] = Key('q', Vector2D(1, 0), 1);
    lowercaseKeys[1][1] = Key('w', Vector2D(1, 1), 1);
    lowercaseKeys[1][2] = Key('e', Vector2D(1, 2), 1);
    lowercaseKeys[1][3] = Key('r', Vector2D(1, 3), 1);
    lowercaseKeys[1][4] = Key('t', Vector2D(1, 4), 1);
    lowercaseKeys[1][5] = Key('y', Vector2D(1, 5), 1);
    lowercaseKeys[1][6] = Key('u', Vector2D(1, 6), 1);
    lowercaseKeys[1][7] = Key('i', Vector2D(1, 7), 1);
    lowercaseKeys[1][8] = Key('o', Vector2D(1, 8), 1);
    lowercaseKeys[1][9] = Key('p', Vector2D(1, 9), 1);

    lowercaseKeys[2][0] = Key('a', Vector2D(2, 0), 1);
    lowercaseKeys[2][1] = Key('s', Vector2D(2, 1), 1);
    lowercaseKeys[2][2] = Key('d', Vector2D(2, 2), 1);
    lowercaseKeys[2][3] = Key('f', Vector2D(2, 3), 1);
    lowercaseKeys[2][4] = Key('g', Vector2D(2, 4), 1);
    lowercaseKeys[2][5] = Key('h', Vector2D(2, 5), 1);
    lowercaseKeys[2][6] = Key('j', Vector2D(2, 6), 1);
    lowercaseKeys[2][7] = Key('k', Vector2D(2, 7), 1);
    lowercaseKeys[2][8] = Key('l', Vector2D(2, 8), 1);
    lowercaseKeys[2][9] = Key('!', Vector2D(2, 9), 1);

    lowercaseKeys[3][0] = Key('z', Vector2D(3, 0), 1);
    lowercaseKeys[3][1] = Key('x', Vector2D(3, 1), 1);
    lowercaseKeys[3][2] = Key('c', Vector2D(3, 2), 1);
    lowercaseKeys[3][3] = Key('v', Vector2D(3, 3), 1);
    lowercaseKeys[3][4] = Key('b', Vector2D(3, 4), 1);
    lowercaseKeys[3][5] = Key('n', Vector2D(3, 5), 1);
    lowercaseKeys[3][6] = Key('m', Vector2D(3, 6), 1);
    lowercaseKeys[3][7] = Key(',', Vector2D(3, 7), 1);
    lowercaseKeys[3][8] = Key('.', Vector2D(3, 8), 1);
    lowercaseKeys[3][9] = Key('?', Vector2D(3, 9), 1);
}

void Keyboard::initCapitalizeKeys() {
    capitalizeKeys[0][0] = Key('1', Vector2D(0, 0), 1);
    capitalizeKeys[0][1] = Key('2', Vector2D(0, 1), 1);
    capitalizeKeys[0][2] = Key('3', Vector2D(0, 2), 1);
    capitalizeKeys[0][3] = Key('4', Vector2D(0, 3), 1);
    capitalizeKeys[0][4] = Key('5', Vector2D(0, 4), 1);
    capitalizeKeys[0][5] = Key('6', Vector2D(0, 5), 1);
    capitalizeKeys[0][6] = Key('7', Vector2D(0, 6), 1);
    capitalizeKeys[0][7] = Key('8', Vector2D(0, 7), 1);
    capitalizeKeys[0][8] = Key('9', Vector2D(0, 8), 1);
    capitalizeKeys[0][9] = Key('0', Vector2D(0, 9), 1);

    capitalizeKeys[1][0] = Key('Q', Vector2D(1, 0), 1);
    capitalizeKeys[1][1] = Key('W', Vector2D(1, 1), 1);
    capitalizeKeys[1][2] = Key('E', Vector2D(1, 2), 1);
    capitalizeKeys[1][3] = Key('R', Vector2D(1, 3), 1);
    capitalizeKeys[1][4] = Key('T', Vector2D(1, 4), 1);
    capitalizeKeys[1][5] = Key('Y', Vector2D(1, 5), 1);
    capitalizeKeys[1][6] = Key('U', Vector2D(1, 6), 1);
    capitalizeKeys[1][7] = Key('I', Vector2D(1, 7), 1);
    capitalizeKeys[1][8] = Key('O', Vector2D(1, 8), 1);
    capitalizeKeys[1][9] = Key('P', Vector2D(1, 9), 1);

    capitalizeKeys[2][0] = Key('A', Vector2D(2, 0), 1);
    capitalizeKeys[2][1] = Key('S', Vector2D(2, 1), 1);
    capitalizeKeys[2][2] = Key('D', Vector2D(2, 2), 1);
    capitalizeKeys[2][3] = Key('F', Vector2D(2, 3), 1);
    capitalizeKeys[2][4] = Key('G', Vector2D(2, 4), 1);
    capitalizeKeys[2][5] = Key('H', Vector2D(2, 5), 1);
    capitalizeKeys[2][6] = Key('J', Vector2D(2, 6), 1);
    capitalizeKeys[2][7] = Key('K', Vector2D(2, 7), 1);
    capitalizeKeys[2][8] = Key('L', Vector2D(2, 8), 1);
    capitalizeKeys[2][9] = Key('!', Vector2D(2, 9), 1);

    capitalizeKeys[3][0] = Key('Z', Vector2D(3, 0), 1);
    capitalizeKeys[3][1] = Key('X', Vector2D(3, 1), 1);
    capitalizeKeys[3][2] = Key('C', Vector2D(3, 2), 1);
    capitalizeKeys[3][3] = Key('V', Vector2D(3, 3), 1);
    capitalizeKeys[3][4] = Key('B', Vector2D(3, 4), 1);
    capitalizeKeys[3][5] = Key('N', Vector2D(3, 5), 1);
    capitalizeKeys[3][6] = Key('M', Vector2D(3, 6), 1);
    capitalizeKeys[3][7] = Key(',', Vector2D(3, 7), 1);
    capitalizeKeys[3][8] = Key('.', Vector2D(3, 8), 1);
    capitalizeKeys[3][9] = Key('?', Vector2D(3, 9), 1);
}

void Keyboard::initSpecialKeys() {
    backspace = Key('\b', "Backspace", Vector2D(4, 0), 2);
    space = Key(' ', "Space", Vector2D(4, 2), 6);
    enter = Key('\n', "Enter", Vector2D(4, 8), 2);
}

void Keyboard::cursorUp() {
    if (cursorPosition.x() > 0) {
        cursorPosition = Vector2D(cursorPosition.x() - 1, cursorPosition.y());
    }
}

void Keyboard::cursorDown() {
    if (cursorPosition.x()  < 4) {
        cursorPosition = Vector2D(cursorPosition.x() + 1, cursorPosition.y());
    } 
}

void Keyboard::cursorLeft() {
    if (cursorPosition.x() < 4) {
        if (cursorPosition.y() > 0) {
            cursorPosition = Vector2D(cursorPosition.x(), cursorPosition.y() - 1);
        }
    }
    else if (cursorPosition.x() == 4) {
        if (cursorPosition.y() >= 8) {
            cursorPosition = Vector2D(4, 8);
        }
        else if (cursorPosition.y() >= 2) {
            cursorPosition = Vector2D(4, 1);
        }
    
    }
}

void Keyboard::cursorRight() {
    if (cursorPosition.x() < 4) {
        if (cursorPosition.y() < 9) {
            cursorPosition = Vector2D(cursorPosition.x(), cursorPosition.y() + 1);
        }
    }
    else if (cursorPosition.x() == 4) {
        if (cursorPosition.y() <= 1) {
            cursorPosition = Vector2D(4, 2);
        }
        else if (cursorPosition.y() <= 7) {
            cursorPosition = Vector2D(4, 8);
        }
    }
}

Key Keyboard::getCurrentKey() {
    if (cursorPosition.x() < 4) {
        if (isCapitalized) {
            return capitalizeKeys[cursorPosition.x()][cursorPosition.y()];
        }
        else {
            return lowercaseKeys[cursorPosition.x()][cursorPosition.y()];
        }
    }
    else if (cursorPosition.x() == 4) {
        if (cursorPosition.y() < 2) {
            return backspace;
        }
        else if (cursorPosition.y() >= 2 && cursorPosition.y() <= 8) {
            return space;
        }
        else if (cursorPosition.y() > 8) {
            return enter;
        }
    }
    return Key();
}

std::vector<Key> Keyboard::getKeys() {
    std::vector<Key> keys;
    
    if (isCapitalized) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 10; j++) {
                keys.push_back(capitalizeKeys[i][j]);
            }
        }
    }
    else {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 10; j++) {
                keys.push_back(lowercaseKeys[i][j]);
            }
        }
    }

    keys.push_back(backspace);
    keys.push_back(space);
    keys.push_back(enter);
    return keys;
}