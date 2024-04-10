#ifndef Key_H
#define Key_H

#include <string>

#include "../Vector2D.h"

/**
 * @brief Class representing single key on keyboard.
 * 
 */
class Key {

public:
    /**
     * @brief Construct a new Key object.
     * @param character Key character. This field works like key (button) identifier.
     * @param stringRepresentation key string representation. This field works like key (button) label. For example "SPACE" for ' '.
     * @param position Position of the key on the keyboard.
     * @param width Width of the key.
     */
    Key(char character, std::string stringRepresentation, Vector2D position, int width);

    /**
     * @brief Construct a new Key object.
     * @param character Key character. This field works like key (button) identifier.
     * @param position Position of the key on the keyboard.
     * @param width Width of the key.
     * String represenation is set to character.
     */
    Key(char character, Vector2D position, int width);

    /**
     * @brief Construct a new Key object.
     * Default constructor using for initialization array of keys.
     */
    Key();

    /**
     * @brief Get string representation of the key.
     * 
     * @return std::string String representation of the key. For example "SPACE" for ' '.
     */
    std::string toString();

    char getCharacter();

    Vector2D getPosition();

    int getWidth();

private:
    char character; /**< Key character. Thanks by this field we can identifiy pressed button. */

    std::string stringRepresentation;

    Vector2D position;

    int width;
};


#endif