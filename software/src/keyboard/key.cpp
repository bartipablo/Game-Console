#include "Key.h"

namespace keyboard {

const int CAPS_LOCK {7};

Key::Key(char character, std::string stringRepresentation, Vector2D position, int width) 
: character{character}, stringRepresentation{stringRepresentation}, position{position}, width{width} {}


Key::Key(char character, Vector2D position, int width) 
: character{character}, stringRepresentation{std::string(1, character)}, position{position}, width{width} {}


Key::Key() 
: character{'\0'}, stringRepresentation{"NULL"}, position{Vector2D(0, 0)}, width{1} {}


std::string Key::toString() const {
    return stringRepresentation;
}


char Key::getCharacter() const {
    return character;
}


Vector2D Key::getPosition() const {
    return position;
}


int Key::getWidth() const {
    return width;
}

}