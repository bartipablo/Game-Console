#ifndef WiFiDisplay_H
#define WiFiDisplay_H

#include <string>

#include "DigitalLCD.h"
#include "Color.h"
#include "WiFiNetwork.h"
#include "WiFiEncriptionType.h"
#include "BasicDisplay.h"

/**
 * Functions to display the WiFi connection status and information.
 */

namespace wifidisplay {

void clearConnectionStatus();

void displayConnetionStatus(bool connected, const char* ssid);

void displayStatus(std::string message);

void displayWEPInformation();

void displayNetwork(wifi::WiFiNetwork network);

void displayPassword(std::string password);

void drawBelowMessage(std::string message);

}

#endif