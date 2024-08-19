#include "PaintApplication.h"

void PaintApplication::start() {
    PaintEngine paint {};
    paint.run();
}

void PaintApplication::display() {
    using namespace mainmenudisplay;
    using basicdisplay::clearScreen;

    PaintIcon paintIcon {};

    clearScreen();
    drawIcon(paintIcon);
    drawTitle(title);
    drawButtonInfo();
}