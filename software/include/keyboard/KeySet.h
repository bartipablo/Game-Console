#ifndef KeySet_H
#define KeySet_H

#include "Key.h"

namespace keyboard {

extern const int ROWS;

extern const int COLUMNS;

/**
 * @brief Class representing a set of keys.
 * for example, a set of lowercase keys for a keyboard.
 */
class KeySet {

public:
    void setKey(int row, int column, Key key);

    Key getKey(int row, int column);

    constexpr static int ROWS_INIT {4};

    constexpr static int COLUMNS_INIT {10};

private:
    Key keys[ROWS_INIT][COLUMNS_INIT];
};

}

#endif