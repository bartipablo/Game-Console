#include "ServerMetadataInput.h"

void ServerMetadataInputDisplay::clearScreen() {
    display->fillScreen(Color::BLACK_);
}


void ServerMetadataInputDisplay::drawIPv4AndPortInputInfo(Color colorIPv4, Color colorPort) {

    uint8_t originalRotation = display->getRotation();
    display->setRotation(3); 

    display->setCursor(0, 10);
    display->setTextColor(Color::WHITE_);
    display->setTextSize(2);
    display->println("Enter server IP and port:");
    display->println("");
    display->setTextColor(colorIPv4.getColorRGB565());
    display->println("IPv4:");
    display->println("");
    display->setTextColor(colorPort.getColorRGB565());
    display->println("Port:");

    display->setRotation(originalRotation);
}


void ServerMetadataInputDisplay::drawInputIPv4(std::string IPv4) {
    uint8_t originalRotation = display->getRotation();
    display->setRotation(3); 

    display->setTextColor(Color::GREEN_); 

    display->setTextSize(2);
    display->fillRect(70, 42, 320, 20, Color::BLACK_);
    display->setCursor(70, 42);
    display->print(IPv4.c_str());

    display->setRotation(originalRotation);
}

void ServerMetadataInputDisplay::drawInputPort(std::string port) {
    uint8_t originalRotation = display->getRotation();
    display->setRotation(3); 

    display->setTextColor(Color::GREEN_); 

    display->setTextSize(2);
    display->fillRect(70, 72, 320, 20, Color::BLACK_);
    display->setCursor(70, 72);
    display->print(port.c_str());

    display->setRotation(originalRotation);
}

void ServerMetadataInputDisplay::drawCommunicate(std::string message, Color color, bool blocking=false) {
    uint8_t originalRotation = display->getRotation();
    display->setRotation(3); 

    display->setTextSize(2);
    display->fillRect(0, 90, 320, 50, Color::GREEN_);
    display->setCursor(0, 100);
    display->setTextColor(color.getColorRGB565()); 
    display->print(message.c_str());

    display->setTextSize(1);

    if (!blocking) {
        display->setCursor(60, 200);
        display->setTextColor(Color::WHITE_);
        display->print("Press left button to continue");
    }


    display->setRotation(originalRotation);
}
