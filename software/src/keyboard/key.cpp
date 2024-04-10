#include "key.h"

Key::Key(char character, std::string stringRepresentation, Vector2D position, int width) {
    Key(character, position, width);
    this->stringRepresentation = stringRepresentation;
}

Key::Key(char character, Vector2D position, int width) {
    this->character = character;
    this->stringRepresentation = std::string(1, character);
    this->position = position;
    this->width = width;
}

std::string Key::toString() {
    return stringRepresentation;
}

char Key::getCharacter() {
    return character;
}
