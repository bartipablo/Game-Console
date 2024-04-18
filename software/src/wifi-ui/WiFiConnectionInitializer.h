#ifndef WiFiConnectionInitializer_H
#define WiFiConnectionInitializer_H

#include <string>

#include "../utils/UserInput.h"
#include "../utils/InputBlocking.h"
#include "../utils/wifi/WiFiConnection.h"
#include "../utils/wifi/WiFiNetwork.h"
#include "../keyboard/Keyboard.h"
#include "../keyboard/KeyboardDisplay.h"
#include "WiFiDisplay.h"

class WiFiConnectionInitializer {
public:
    WiFiConnectionInitializer(WiFiDisplay* display, WiFiNetwork wifiNetwork) : wifiNetwork(wifiNetwork) {
        this->display = display;
        inputBlocking = new InputBlocking();
        keyboard = new Keyboard();
        keyboardDisplay = new KeyboardDisplay();
        shutdown = false;
    }

    ~WiFiConnectionInitializer() {
        delete inputBlocking;
        delete keyboard;
        delete keyboardDisplay;
    }

    void run();

private:
    InputBlocking* inputBlocking;

    Keyboard* keyboard;

    KeyboardDisplay* keyboardDisplay;

    WiFiConnection* wifiConnection = WiFiConnection::getInstance();

    UserInput* userInput = UserInput::getInstance();

    WiFiDisplay* display;

    WiFiNetwork wifiNetwork;

    std::string password;

    bool shutdown;

    void updateKey(Key previousKey, Key currentKey);

    void serveKey(Key key);

};

#endif
