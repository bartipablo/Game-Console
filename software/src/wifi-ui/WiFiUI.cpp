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
                
                // If we have a saved network, we disconnect it 
                if (strcmp("", wifiConnection->getLastSSID()) != 0) {
                    wifiConnection->disconnect();
                }
                else {
                    runWiFiNetworkSelectionMenu();
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
    display->clear();
    display->displayStatus("Loading...");
    std::vector<wifi::WiFiNetwork> networks = wifiConnection->scanNetworks();
    std::vector<App*> networkUIs;

    if (networks.size() == 0) {
        display->displayStatus("No networks found.");
        delay(2000);
        return;
    }
    
    for (wifi::WiFiNetwork network : networks) {
        networkUIs.push_back(new WiFiNetworkUI(display, network));
    }

    AppMenu* findedNetworksMenu = new AppMenu(networkUIs);
    findedNetworksMenu->setAutoExit(true);
    findedNetworksMenu->setLoopedMenu(true);

    findedNetworksMenu->start();

    delete findedNetworksMenu;
}

void WiFiUI::refreshConnectionStatus() {
    display->clear();

    if (strcmp("", wifiConnection->getLastSSID()) == 0) {
        display->drawBelowMessage("Press left button to scan networks.");
    } else {
        display->drawBelowMessage("Press left button to disable WiFi.");
    }

    previousConnectionStatus = wifiConnection->isConnected();
    display->displayConnetionStatus(previousConnectionStatus, wifiConnection->getLastSSID());
}