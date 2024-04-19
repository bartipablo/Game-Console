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

/**
 * User interface to manage the WiFi connection
 */
class WiFiUI {
public:
    WiFiUI();

    ~WiFiUI();

/**
 * Run the WiFi user interface
*/
    void run();

private:
    bool previousConnectionStatus;

    WiFiConnection* wifiConnection = WiFiConnection::getInstance();

    UserInput* userInput = UserInput::getInstance();

    WiFiDisplay* display;

    InputBlocking* inputBlocking;

/**
 * Run the WiFi network selection menu
 * It will display the available networks and allow the user to select one.
*/
    void runWiFiNetworkSelectionMenu();

/**
 * display connection status
 */
    void refreshConnectionStatus();
};

#endif
