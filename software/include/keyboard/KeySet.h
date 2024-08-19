#ifndef KeySet_H
#define KeySet_H

#include "Key.h"

#define ROWS 4
#define COLUMNS 10


/**
 * @brief Class representing a set of keys.
 * for example, a set of lowercase keys for a keyboard.
 */
class KeySet {

public:
    void setKey(int row, int column, Key key) {
        if (row < 0 || row >= ROWS || column < 0 || column >= COLUMNS) {
            return;
        }
        keys[row][column] = key;
    }

    Key getKey(int row, int column) {
        if (row < 0 || row >= ROWS || column < 0 || column >= COLUMNS) {
            return Key();
        }
        return keys[row][column];
    }

private:
    Key keys[ROWS][COLUMNS];
};


#endif