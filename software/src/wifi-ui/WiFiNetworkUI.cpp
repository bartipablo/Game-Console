#include "WiFiNetworkUI.h"

WiFiNetworkUI::WiFiNetworkUI(WiFiDisplay* wifiDisplay, WiFiNetwork wifiNetwork) 
    : wifiNetwork(wifiNetwork) {
    this->wifiDisplay = wifiDisplay;
    inputBlocking = new InputBlocking();
    wifiConnection = WiFiConnection::getInstance();
}

WiFiNetworkUI::~WiFiNetworkUI() {
    delete inputBlocking;
}

void WiFiNetworkUI::start() {
    WiFiConnectionInitializer* wifiConnectionInitializer = new WiFiConnectionInitializer(wifiDisplay, wifiNetwork);
    wifiConnectionInitializer->run();
    delete wifiConnectionInitializer;
}

void WiFiNetworkUI::display() {
    wifiDisplay->displayNetwork(wifiNetwork);
    wifiDisplay->drawBelowMessage("Press left button to connect.");
}