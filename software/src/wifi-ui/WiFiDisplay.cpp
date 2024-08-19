#include "WiFiDisplay.h"

namespace wifidisplay {

void clearConnectionStatus() {
    Arduino_ILI9341* display = DigitalLCD::getInstance();
    display->fillRect(60, 20, 320, 65, Color::BLACK_);
}

void displayConnetionStatus(bool connected, const char* ssid) {
    Arduino_ILI9341* display = DigitalLCD::getInstance();

    display->setCursor(0, 20);
    display->setTextColor(Color::WHITE_);
    display->setTextSize(2);
    display->print("WiFi: ");
    if (connected) {
        display->setTextColor(Color::GREEN_);
        display->print("Connected");
    } else {
        display->setTextColor(Color::RED_);
        display->print("Disconnected");
    }
    display->setCursor(0, 60);
    display->setTextColor(Color::WHITE_);
    display->print("SSID: ");
    display->setTextColor(Color::YELLOW_);
    display->print(ssid);
}

void displayStatus(std::string message) {
    Arduino_ILI9341* display = DigitalLCD::getInstance();

    basicdisplay::clearScreen();
    display->setCursor(100, 100);
    display->setTextColor(Color::WHITE_);
    display->setTextSize(2);
    display->print(message.c_str());
}

void displayWEPInformation() {
    Arduino_ILI9341* display = DigitalLCD::getInstance();

    basicdisplay::clearScreen();
    display->setCursor(0, 20);
    display->setTextColor(Color::WHITE_);
    display->setTextSize(2);
    display->print("WEP encryption is not supported yet :(");
}

void displayNetwork(wifi::WiFiNetwork network) {
    Arduino_ILI9341* display = DigitalLCD::getInstance();

    basicdisplay::clearScreen();
    display->setCursor(0, 20);
    display->setTextColor(Color::WHITE_);
    display->setTextSize(2);
    display->print(network.getSSID());
    
    display->setTextColor(Color::YELLOW_);
    display->setCursor(0, 40);
    display->print("RSSI: ");
    display->print(network.getRSSI());

    display->setCursor(0, 60);
    display->print("Encryption: ");
    display->print(
        wifi::toStringEncriptionType(network.getEncryptionType()).c_str()
    );
}

void displayPassword(std::string password) {
    Arduino_ILI9341* display = DigitalLCD::getInstance();

    display->fillRect(0, 40, 320, 80, Color::BLACK_);
    display->setCursor(0, 20);
    display->setTextColor(Color::WHITE_);
    display->setTextSize(2);
    display->print("Password: ");
    display->setTextColor(Color::YELLOW_);
    display->setCursor(0, 40);
    display->print(password.c_str());
}

void drawBelowMessage(std::string message) {
    Arduino_ILI9341* display = DigitalLCD::getInstance();

    display->setTextSize(1);
    display->setTextColor(Color::WHITE_);
    display->setCursor(60, 240 - 20);
    display->print(message.c_str());
}

}