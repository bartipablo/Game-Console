
#include "KeySet.h"

namespace keyboard {

const int ROWS {KeySet::ROWS_INIT};

const int COLUMNS {KeySet::COLUMNS_INIT};


void KeySet::setKey(int row, int column, Key key) {
    if (row < 0 || row >= ROWS || column < 0 || column >= COLUMNS) {
        return;
    }
    keys[row][column] = key;
}


Key KeySet::getKey(int row, int column) {
    if (row < 0 || row >= ROWS || column < 0 || column >= COLUMNS) {
        return Key();
    }
    return keys[row][column];
}

}
