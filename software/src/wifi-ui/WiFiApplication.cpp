#include "WiFiApplication.h"


void WiFiApplication::start() {
    WiFiUI wifiUI {};
    wifiUI.run();
}


void WiFiApplication::display() {
    using namespace mainmenudisplay;
    using basicdisplay::clearScreen;

    WiFiIcon wifiIcon {};

    clearScreen();
    drawIcon(wifiIcon);
    drawTitle(title);
    drawButtonInfo();
}