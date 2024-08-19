#include "SnakeApplication.h"


void SnakeApplication::start() {
    snake::SnakeEngine snake {};
    snake.run();
}


void SnakeApplication::display() {
    using namespace mainmenudisplay;
    using basicdisplay::clearScreen;

    snake::SnakeIcon snakeIcon {};

    clearScreen();
    drawIcon(snakeIcon);
    drawTitle(title);
    drawButtonInfo();
}