#ifndef WiFiDisplay_H
#define WiFiDisplay_H

#include <string>

#include "../utils/DigitalLCD.h"
#include "../common/Color.h"
#include "../utils/wifi/WiFiNetwork.h"
#include "../utils/wifi/WiFiEncriptionType.h"

class WiFiDisplay {
public:
    void clear();

    void clearConnectionStatus();

    void displayConnetionStatus(bool connected, const char* ssid);

    void displayLoading();

    void displayWEPInformation();

    void displayNetwork(WiFiNetwork network);

    void displayPassword(std::string password);

    void drawBelowMessage(std::string message);

private:
    Arduino_ILI9341* display = DigitalLCD::getInstance();
};

#endif