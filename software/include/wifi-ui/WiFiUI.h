#ifndef WiFiUI_H
#define WiFiUI_H

#include <vector>
#include <string.h>

#include "WiFiNetworkUI.h"
#include "WiFiDisplay.h"
#include "AppMenu.h"
#include "UserInput.h"
#include "InputBlocking.h"
#include "WiFiConnection.h"
#include "WiFiEncriptionType.h"
#include "WiFiNetwork.h"

/**
 * User interface to manage the WiFi connection
 */
class WiFiUI {
public:
    WiFiUI();

/**
 * Run the WiFi user interface
*/
    void run();

private:
    bool previousConnectionStatus;

    wifi::WiFiConnection* wifiConnection = wifi::WiFiConnection::getInstance();

    UserInput* userInput = UserInput::getInstance();

    InputBlocking inputBlocking;

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
