#ifndef WiFiNetworkUI_H
#define WiFiNetworkUI_H

#include <string>

#include "../app-menu/App.h" 
#include "../utils/wifi/WiFiNetwork.h"
#include "../utils/wifi/WiFiEncriptionType.h"
#include "../utils/wifi/WiFiConnection.h"
#include "../utils/InputBlocking.h"
#include "WiFiDisplay.h"
#include "WiFiConnectionInitializer.h"

/**
 * Represents the single network in the WiFi network selection menu.
 */
class WiFiNetworkUI : public App {
public:
    WiFiNetworkUI(WiFiDisplay* wifiDisplay, wifi::WiFiNetwork wifiNetwork);

    ~WiFiNetworkUI();

/**
 * It will run when the user selects the network.
*/
    void start() override;

/**
 * Display the network information in selection menu.
 */
    void display() override;

private:
    wifi::WiFiConnection* wifiConnection = wifi::WiFiConnection::getInstance();

    InputBlocking* inputBlocking;

    std::string title;

    wifi::WiFiNetwork wifiNetwork;

    WiFiDisplay* wifiDisplay;    
};

#endif
