#include "WiFiNetworkUI.h"

WiFiNetworkUI::WiFiNetworkUI(wifi::WiFiNetwork wifiNetwork) 
    : wifiNetwork(wifiNetwork), wifiConnection{wifi::WiFiConnection::getInstance()} {
}

void WiFiNetworkUI::start() {
    WiFiConnectionInitializer wifiConnectionInitializer {wifiNetwork};
    wifiConnectionInitializer.run();
}

void WiFiNetworkUI::display() {
    using namespace wifidisplay;

    displayNetwork(wifiNetwork);
    drawBelowMessage("Press left button to connect.");
}