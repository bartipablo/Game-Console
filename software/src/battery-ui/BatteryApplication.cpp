#include "BatteryApplication.h"


void BatteryApplication::start() {
    BatteryUI batteryUI {};
    batteryUI.run();
}


void BatteryApplication::display() {
    using namespace mainmenudisplay;
    using basicdisplay::clearScreen;

    BatteryIcon batteryIcon {};

    clearScreen();
    drawIcon(batteryIcon);
    drawTitle(title);
    drawButtonInfo();
}