#include "UserInput.h"

UserInput *UserInput::userInput_ = nullptr;

UserInput::UserInput(const int leftButtonPin, const int rightButtonPin, const int joysticXPin, const int joysticYPin, const int joysticButtonPin)
    : leftButtonPin_(leftButtonPin),
      rightButtonPin_(rightButtonPin),
      joysticXPin_(joysticXPin),
      joysticYPin_(joysticYPin),
      joysticButtonPin_(joysticButtonPin)
{

    pinMode(leftButtonPin_, INPUT_PULLUP);
    pinMode(rightButtonPin_, INPUT_PULLUP);
    pinMode(joysticButtonPin_, INPUT_PULLUP);
}

bool UserInput::isPressedLeftButton() {
    return digitalRead(leftButtonPin_) == LOW;
}

bool UserInput::isPressedRightButton() {
    return digitalRead(rightButtonPin_) == LOW;
}

bool UserInput::isPressedJoysticUp() {
    return getYJoysticVal() < 1;
}

bool UserInput::isPressedJoysticDown() {
    return getYJoysticVal() > 254;
}

bool UserInput::isPressedJoysticLeft() {
    return getXJoysticVal() > 254;
}

bool UserInput::isPressedJoysticRight() {
    return getXJoysticVal() < 1;
}

bool UserInput::isPressedJoysticButton() {
    return digitalRead(joysticButtonPin_) == LOW;
}

int UserInput::getXJoysticVal() {
    return (analogRead(joysticXPin_) >> 4);
}

int UserInput::getYJoysticVal() {
    return (analogRead(joysticYPin_) >> 4);
}

void UserInput::init(int leftButtonPin, int rightButtonPin, int joysticXPin, int joysticYPin, int joysticButtonPin) {
    if (userInput_ != nullptr) {
        throw ForbiddenOperation("UserInput has already been initialized.");
    }
    userInput_ = new UserInput(leftButtonPin, rightButtonPin, joysticXPin, joysticYPin, joysticButtonPin);
}

UserInput *UserInput::getInstance() {
    return userInput_;
}
