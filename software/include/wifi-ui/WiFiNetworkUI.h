#ifndef WiFiNetworkUI_H
#define WiFiNetworkUI_H

#include <string>

#include "App.h" 
#include "WiFiNetwork.h"
#include "WiFiEncriptionType.h"
#include "WiFiConnection.h"
#include "InputBlocking.h"
#include "WiFiDisplay.h"
#include "WiFiConnectionInitializer.h"

/**
 * Represents the single network in the WiFi network selection menu.
 */
class WiFiNetworkUI : public App {
public:
    WiFiNetworkUI(wifi::WiFiNetwork wifiNetwork);

/**
 * It will run when the user selects the network.
*/
    void start() override;

/**
 * Display the network information in selection menu.
 */
    void display() override;

private:
    wifi::WiFiConnection* wifiConnection;

    std::string title;

    wifi::WiFiNetwork wifiNetwork;
};

#endif
