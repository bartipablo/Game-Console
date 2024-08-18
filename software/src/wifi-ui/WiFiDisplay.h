#ifndef WiFiDisplay_H
#define WiFiDisplay_H

#include <string>

#include "DigitalLCD.h"
#include "Color.h"
#include "../utils/wifi/WiFiNetwork.h"
#include "../utils/wifi/WiFiEncriptionType.h"

/**
 * Class to display the WiFi connection status and information.
 */
class WiFiDisplay {
public:
    void clear();

    void clearConnectionStatus();

    void displayConnetionStatus(bool connected, const char* ssid);

    void displayStatus(std::string message);

    void displayWEPInformation();

    void displayNetwork(wifi::WiFiNetwork network);

    void displayPassword(std::string password);

    void drawBelowMessage(std::string message);

private:
    Arduino_ILI9341* display = DigitalLCD::getInstance();
};

#endif