#ifndef Key_H
#define Key_H

#include <string>

#include "Vector2D.h"

namespace keyboard {

extern const int CAPS_LOCK;

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
     * @param position Position of the key on the keyboard. Used by display.
     * @param width Width of the key. Used by the display.
     */
    Key(char character, std::string stringRepresentation, Vector2D position, int width);

    /**
     * @brief Construct a new Key object.
     * @param character Key character. This field works like key (button) identifier.
     * @param position Position of the key on the keyboard. Used by display.
     * @param width Width of the key. Used by the display.
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
    std::string toString() const;

    /**
     * @brief Get key character.
     * 
     * @return char Key character.
     */
    char getCharacter() const;

    /**
     * @brief Get key position on keyboard. Used by the display.
     * 
     * @return Vector2D Key position.
     */
    Vector2D getPosition() const;

    /**
     * @brief Get key width. Used by the display.
     * 
     * @return int Key width.
     */
    int getWidth() const;

    bool operator==(const Key& other) const {
        return character == other.character;
    }

private:
    char character; /**< Key character. Thanks by this field we can identifiy pressed button. */

    std::string stringRepresentation;

    Vector2D position;

    int width;
};

}

#endif