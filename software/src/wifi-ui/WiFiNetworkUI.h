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

class WiFiNetworkUI : public App {
public:
    WiFiNetworkUI(WiFiDisplay* wifiDisplay, WiFiNetwork wifiNetwork) : wifiNetwork(wifiNetwork) {
        this->wifiDisplay = wifiDisplay;
        inputBlocking = new InputBlocking();
    }

    ~WiFiNetworkUI() {
        delete inputBlocking;
    }

    void start() override;

    void display() override;

private:
    WiFiConnection* wifiConnection = WiFiConnection::getInstance();

    InputBlocking* inputBlocking;

    std::string title;

    WiFiNetwork wifiNetwork;

    WiFiDisplay* wifiDisplay;    
};

#endif
