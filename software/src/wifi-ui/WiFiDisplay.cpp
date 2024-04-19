#include "WiFiDisplay.h"

void WiFiDisplay::clear() {
    display->fillScreen(Color::BLACK_);
}

void WiFiDisplay::clearConnectionStatus() {
    uint8_t originalRotation = display->getRotation();
    display->setRotation(3); 

    display->fillRect(60, 20, 320, 65, Color::BLACK_);

    display->setRotation(originalRotation);
}

void WiFiDisplay::displayConnetionStatus(bool connected, const char* ssid) {
    uint8_t originalRotation = display->getRotation();
    display->setRotation(3); 

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

    display->setRotation(originalRotation);
}

void WiFiDisplay::displayStatus(std::string message) {
    uint8_t originalRotation = display->getRotation();
    display->setRotation(3); 

    clear();
    display->setCursor(100, 100);
    display->setTextColor(Color::WHITE_);
    display->setTextSize(2);
    display->print(message.c_str());

    display->setRotation(originalRotation);
}

void WiFiDisplay::displayWEPInformation() {
    uint8_t originalRotation = display->getRotation();
    display->setRotation(3); 

    clear();
    display->setCursor(0, 20);
    display->setTextColor(Color::WHITE_);
    display->setTextSize(2);
    display->print("WEP encryption is not supported yet :(");

    display->setRotation(originalRotation);
}

void WiFiDisplay::displayNetwork(WiFiNetwork network) {
    clear();
    uint8_t originalRotation = display->getRotation();
    display->setRotation(3); 

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
        toStringEncriptionType(network.getEncryptionType()).c_str()
    );

    display->setRotation(originalRotation);
}

void WiFiDisplay::displayPassword(std::string password) {
    uint8_t originalRotation = display->getRotation();
    display->setRotation(3); 

    display->fillRect(0, 40, 320, 80, Color::BLACK_);
    display->setCursor(0, 20);
    display->setTextColor(Color::WHITE_);
    display->setTextSize(2);
    display->print("Password: ");
    display->setTextColor(Color::YELLOW_);
    display->setCursor(0, 40);
    display->print(password.c_str());

    display->setRotation(originalRotation);
}

void WiFiDisplay::drawBelowMessage(std::string message) {

    uint8_t originalRotation = display->getRotation();
    display->setRotation(3); 

    display->setTextSize(1);
    display->setTextColor(Color::WHITE_);
    display->setCursor(60, 240 - 20);
    display->print(message.c_str());

    display->setRotation(originalRotation);
}