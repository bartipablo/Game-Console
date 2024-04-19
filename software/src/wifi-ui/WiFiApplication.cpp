#include "WiFiApplication.h"

WiFiApplication::WiFiApplication(MainMenuDisplay* menuDisplay) {
    title = "WiFi";
    this->menuDisplay = menuDisplay;
}

void WiFiApplication::start() {
    WiFiUI* wifiUI = new WiFiUI();
    wifiUI->run();
    delete wifiUI;
}

void WiFiApplication::display() {
    Icon* wifiIcon = new WiFiIcon();

    menuDisplay->clear();
    menuDisplay->drawIcon(*wifiIcon);
    menuDisplay->drawTitle(title);
    menuDisplay->drawButtonInfo();

    delete wifiIcon;
}