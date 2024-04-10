#ifndef Key_H
#define Key_H

#include <string>

#include "../Vector2D.h"

/**
 * @brief Class representing single key.
 * 
 */
class Key {

public:
    /**
     * @brief Construct a new Key object.
     * 
     * @param stringRepresentation key stringRepresentation.
     * @param position Position of the key on the keyboard.
     * @param width Width of the key.
     */
    Key(char character, std::string stringRepresentation, Vector2D position, int width);

    Key(char character, Vector2D position, int width);

    std::string toString();

    char getCharacter();

private:
    char character; // key character.

    std::string stringRepresentation; // key stringRepresentation.

    Vector2D position;  /**< Position of the key on the keyboard. */

    int width;  /**< Width of the key. */
};


#endif