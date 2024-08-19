#include "WiFiConnectionInitializer.h"

WiFiConnectionInitializer::WiFiConnectionInitializer(wifi::WiFiNetwork wifiNetwork) 
    : wifiNetwork(wifiNetwork), keyboard_{keyboard::KeyboardFactory::createClassicKeyboard()}, wifiConnection{wifi::WiFiConnection::getInstance()}, userInput{UserInput::getInstance()}, shutdown{false} {
}

void WiFiConnectionInitializer::run() {
    using namespace wifidisplay;

    wifi::WiFiEncriptionType encriptionType = wifiNetwork.getEncryptionType();

    if (encriptionType == wifi::WiFiEncriptionType::WEP) {
        displayWEPInformation();
        delay(2000);
        return;
    }

    keyboard::StandardKeyboardService standardKeyboardService {keyboard_};

    inputBlocking->startBlocking(20);
    standardKeyboardService.registerInputBlocking(inputBlocking, 10);

    basicdisplay::clearScreen();
    displayPassword(password);
    standardKeyboardService.displayKeyboard();

    while (!shutdown) {
        delay(20);
        
        if (!inputBlocking->isBlocked()) {
            standardKeyboardService.serveUserInteraction();

            if (userInput->isPressedLeftButton()) {
                serveKey(keyboard_.getCurrentKey());
            }
            else if (userInput->isPressedRightButton()) {
                return;
            }
        }
        inputBlocking->decrement();
            
    }
}

void WiFiConnectionInitializer::serveKey(keyboard::Key key) {
    using namespace wifidisplay;
    using keyboard::CAPS_LOCK;

    if (key.getCharacter() == CAPS_LOCK) {
        // ignore this case.
    }
    else if (key.getCharacter() == '\b') {
        if (password.length() > 0) {
            password.pop_back();
            displayPassword(password);
        }
    }
    else if (key.getCharacter() == '\n') {
        wifiConnection->connectToWiFi(wifiNetwork.getSSID(), password.c_str());
        shutdown = true;
        return;
    }
    else if (password.length() < 64) {
        password += key.getCharacter();
        displayPassword(password);
    }
}