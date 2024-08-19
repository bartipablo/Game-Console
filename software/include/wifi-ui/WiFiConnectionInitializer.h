#ifndef WiFiConnectionInitializer_H
#define WiFiConnectionInitializer_H

#include <string>

#include "UserInput.h"
#include "InputBlocking.h"
#include "WiFiConnection.h"
#include "WiFiNetwork.h"
#include "Keyboard.h"
#include "KeyboardDisplay.h"
#include "KeyboardFactory.h"
#include "StandardKeyboardService.h"
#include "WiFiDisplay.h"
#include "Key.h"

/**
 * Class to initialize the WiFi connection.
 * It will display the password input and connect to the network.
*/
class WiFiConnectionInitializer {
public:
    WiFiConnectionInitializer(wifi::WiFiNetwork wifiNetwork);

/**
 * Run the WiFi connection initializer.
 * It's main function to run the WiFi connection initializer.
 * It will display the password input and handle logic to connect to the network.
*/
    void run();

private:
    InputBlocking inputBlocking;

    keyboard::Keyboard keyboard_;

    wifi::WiFiConnection* wifiConnection = wifi::WiFiConnection::getInstance();

    UserInput* userInput = UserInput::getInstance();

    wifi::WiFiNetwork wifiNetwork;

    std::string password;

    bool shutdown;

/**
 * handle the keyboard input.
*/
    void serveKey(keyboard::Key key);

};

#endif
