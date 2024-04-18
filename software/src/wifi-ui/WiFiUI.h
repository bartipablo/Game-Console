#ifndef WiFiUI_H
#define WiFiUI_H

#include <vector>
#include <string.h>

#include "WiFiNetworkUI.h"
#include "WiFiDisplay.h"
#include "../app-menu/AppMenu.h"
#include "../utils/UserInput.h"
#include "../utils/InputBlocking.h"
#include "../utils/wifi/WiFiConnection.h"
#include "../utils/wifi/WiFiEncriptionType.h"
#include "../utils/wifi/WiFiNetwork.h"

class WiFiUI {
public:
    WiFiUI();

    ~WiFiUI();

    void run();

private:
    bool previousConnectionStatus;

    WiFiConnection* wifiConnection = WiFiConnection::getInstance();

    UserInput* userInput = UserInput::getInstance();

    WiFiDisplay* display;

    InputBlocking* inputBlocking;

    void runWiFiNetworkSelectionMenu();

    void refreshConnectionStatus();
};

#endif
