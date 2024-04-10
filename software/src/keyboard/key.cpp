#include "Key.h"

Key::Key(char character, std::string stringRepresentation, Vector2D position, int width) {
    this->character = character;
    this->stringRepresentation = stringRepresentation;
    this->position = position;
    this->width = width;
}

Key::Key(char character, Vector2D position, int width) {
    this->character = character;
    this->stringRepresentation = std::string(1, character);
    this->position = position;
    this->width = width;
}

Key::Key() {
    this->character = 0;
    this->stringRepresentation = "DEFAULT";
    this->position = Vector2D(0, 0);
    this->width = 1;
}

std::string Key::toString() {
    return stringRepresentation;
}

char Key::getCharacter() {
    return character;
}

Vector2D Key::getPosition() {
    return position;
}

int Key::getWidth() {
    return width;
}