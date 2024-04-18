#include "WiFiUI.h"

WiFiUI::WiFiUI() {
    display = new WiFiDisplay();
    inputBlocking = new InputBlocking();
}

WiFiUI::~WiFiUI() {
    delete display;
    delete inputBlocking;
}

void WiFiUI::run() {
    refreshConnectionStatus();

    inputBlocking->startBlocking(30);
    while (true) {
        if (!inputBlocking->isBlocked()) {
            bool newConnectionStatus = wifiConnection->isConnected();
            if (newConnectionStatus != previousConnectionStatus) {
                refreshConnectionStatus();
            }

            if (userInput->isPressedRightButton()) {
                return;
            }

            if (userInput->isPressedLeftButton()) {
                
                if (strcmp("", wifiConnection->getLastSSID()) != 0) {
                    wifiConnection->disconnect();
                }
                else {
                    display->clear();
                    display->displayLoading();
                    std::vector<WiFiNetwork> networks = wifiConnection->scanNetworks();
                    std::vector<App*> networkUIs;
                    
                    for (WiFiNetwork network : networks) {
                        networkUIs.push_back(new WiFiNetworkUI(display, network));
                    }

                    AppMenu* findedNetworksMenu = new AppMenu(networkUIs);
                    findedNetworksMenu->setAutoExit(true);
                    findedNetworksMenu->setLoopedMenu(true);

                    findedNetworksMenu->start();

                    delete findedNetworksMenu;
                }
                refreshConnectionStatus();
                inputBlocking->startBlocking(20);
            }
        }

        inputBlocking->decrement();
        delay(20);

    }
}

void WiFiUI::runWiFiNetworkSelectionMenu() {
    std::vector<WiFiNetwork> networks = wifiConnection->scanNetworks();
    for (int i = 0; i < networks.size(); i++) {
        // display network
    }
}

void WiFiUI::refreshConnectionStatus() {
    previousConnectionStatus = wifiConnection->isConnected();
    display->clear();
    display->displayConnetionStatus(previousConnectionStatus, wifiConnection->getLastSSID());
    if (strcmp("", wifiConnection->getLastSSID()) == 0) {
        display->drawBelowMessage("Press left button to scan networks.");
    } else {
        display->drawBelowMessage("Press left button to disable WiFi.");
    }
}