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

/**
 * Class to initialize the WiFi connection.
 * It will display the password input and connect to the network.
*/
class WiFiConnectionInitializer {
public:
    WiFiConnectionInitializer(WiFiDisplay* display, WiFiNetwork wifiNetwork);

    ~WiFiConnectionInitializer();

/**
 * Run the WiFi connection initializer.
 * It's main function to run the WiFi connection initializer.
 * It will display the password input and handle logic to connect to the network.
*/
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

/**
 * Updating the key on the display.
*/
    void updateKey(Key previousKey, Key currentKey);

/**
 * handle the keyboard input.
*/
    void serveKey(Key key);

};

#endif
