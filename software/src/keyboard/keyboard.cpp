#include "Keyboard.h"

namespace keyboard {

Keyboard::Keyboard(KeySet standardKeySet)
: backspace{Key('\b', "Backspace", Vector2D(4, 0), 2)},
  capsLck{Key(CAPS_LOCK, "CapsLk", Vector2D(4, 2), 2)},
  space{Key(' ', "Space", Vector2D(4, 4), 4)},
  enter{Key('\n', "Enter", Vector2D(4, 8), 2)},
  currentKeySetIndex{0} {

    keySets.push_back(standardKeySet);
}


void Keyboard::cursorUp() {
    if (cursorPosition.x() > 0) {
        cursorPosition = Vector2D(cursorPosition.x() - 1, cursorPosition.y());
    }
}


void Keyboard::cursorDown() {
    if (cursorPosition.x()  < ROWS) {
        cursorPosition = Vector2D(cursorPosition.x() + 1, cursorPosition.y());
    } 
}


void Keyboard::cursorLeft() {
    if (cursorPosition.x() < ROWS) {
        if (cursorPosition.y() > 0) {
            cursorPosition = Vector2D(cursorPosition.x(), cursorPosition.y() - 1);
        }
    }
    else if (cursorPosition.x() == ROWS) {
        if (cursorPosition.y() >= 8) {
            cursorPosition = Vector2D(4, 6);
        }
        else if (cursorPosition.y() >= 4) {
            cursorPosition = Vector2D(4, 3);
        }
        else if (cursorPosition.y() >= 2) {
            cursorPosition = Vector2D(4, 1);
        }
    }
}


void Keyboard::cursorRight() {
    if (cursorPosition.x() < ROWS) {
        if (cursorPosition.y() < COLUMNS - 1) {
            cursorPosition = Vector2D(cursorPosition.x(), cursorPosition.y() + 1);
        }
    }
    else if (cursorPosition.x() == ROWS) {
        if (cursorPosition.y() <= 1) {
            cursorPosition = Vector2D(4, 2);
        }
        else if (cursorPosition.y() < 3) {
            cursorPosition = Vector2D(4, 5);
        }
        else if (cursorPosition.y() <= 7) {
            cursorPosition = Vector2D(4, 8);
        }
    }
}


Key Keyboard::getCurrentKey() {
    KeySet& currentKeySet = keySets.at(currentKeySetIndex);

    if (cursorPosition.x() < ROWS) {
        return currentKeySet.getKey(cursorPosition.x(), cursorPosition.y());
    }
    else if (cursorPosition.y() <= 1) {
        return backspace;
    }
    else if (cursorPosition.y() >= 2 && cursorPosition.y() <= 3) {
        return capsLck;
    }
    else if (cursorPosition.y() >= 4 && cursorPosition.y() <= 7) {
        return space;
    }
    else if (cursorPosition.y() >= 8) {
        return enter;
    }
    return Key {};
}


std::vector<Key> Keyboard::getKeys() {
    KeySet& currentKeySet = keySets.at(currentKeySetIndex);

    std::vector<Key> keys;
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            keys.push_back(currentKeySet.getKey(i, j));
        }
    }

    keys.push_back(backspace);
    keys.push_back(capsLck);
    keys.push_back(space);
    keys.push_back(enter);

    return keys;
}


void Keyboard::addKeySet(KeySet keySet) {
    keySets.push_back(keySet);
}


void Keyboard::changeKeySet() {
    if (currentKeySetIndex >= keySets.size() - 1) {
        currentKeySetIndex = 0;
    } else {
        currentKeySetIndex++;
    }
}

}
