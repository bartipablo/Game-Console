#include "WiFiUI.h"

WiFiUI::WiFiUI() {}


void WiFiUI::run() {
    refreshConnectionStatus();

    inputBlocking.startBlocking(30);
    while (true) {
        if (!inputBlocking.isBlocked()) {
            
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
                inputBlocking.startBlocking(20);
            }
        }

        inputBlocking.decrement();
        delay(20);
    }
}

void WiFiUI::runWiFiNetworkSelectionMenu() {
    using namespace wifidisplay;

    basicdisplay::clearScreen();
    displayStatus("Loading...");
    std::vector<wifi::WiFiNetwork> networks = wifiConnection->scanNetworks();
    std::vector<App*> networkUIs;

    if (networks.size() == 0) {
        displayStatus("No networks found.");
        delay(2000);
        return;
    }
    
    for (wifi::WiFiNetwork network : networks) {
        networkUIs.push_back(new WiFiNetworkUI(network));
    }

    AppMenu* findedNetworksMenu = new AppMenu(networkUIs);
    findedNetworksMenu->setAutoExit(true);
    findedNetworksMenu->setLoopedMenu(true);

    findedNetworksMenu->start();

    delete findedNetworksMenu;
}

void WiFiUI::refreshConnectionStatus() {
    using namespace wifidisplay;

    basicdisplay::clearScreen();

    if (strcmp("", wifiConnection->getLastSSID()) == 0) {
        drawBelowMessage("Press left button to scan networks.");
    } else {
        drawBelowMessage("Press left button to disable WiFi.");
    }

    previousConnectionStatus = wifiConnection->isConnected();
    displayConnetionStatus(previousConnectionStatus, wifiConnection->getLastSSID());
}