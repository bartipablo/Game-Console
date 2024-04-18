#include "WiFiNetworkUI.h"

void WiFiNetworkUI::start() {
    WiFiConnectionInitializer* wifiConnectionInitializer = new WiFiConnectionInitializer(wifiDisplay, wifiNetwork);
    wifiConnectionInitializer->run();
    delete wifiConnectionInitializer;
}



void WiFiNetworkUI::display() {
    wifiDisplay->displayNetwork(wifiNetwork);
    wifiDisplay->drawBelowMessage("Press left button to connect.");
}