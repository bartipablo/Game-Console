#include "TetrisApplication.h"


void TetrisApplication::start() {
    TetrisEngine tetris {};
    tetris.run();
}


void TetrisApplication::display() {
    using namespace mainmenudisplay;
    using basicdisplay::clearScreen;

    TetrisIcon tetrisIcon {};

    clearScreen();
    drawIcon(tetrisIcon);
    drawTitle(title);
    drawButtonInfo();
}