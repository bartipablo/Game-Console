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

/**
 * Class to initialize the WiFi connection.
 * It will display the password input and connect to the network.
*/
class WiFiConnectionInitializer {
public:
    WiFiConnectionInitializer(WiFiDisplay* display, wifi::WiFiNetwork wifiNetwork);

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

    KeyboardFactory* keyboardFactory;

    KeyboardDisplay* keyboardDisplay;

    StandardKeyboardService* standardKeyboardService;

    wifi::WiFiConnection* wifiConnection = wifi::WiFiConnection::getInstance();

    UserInput* userInput = UserInput::getInstance();

    WiFiDisplay* display;

    wifi::WiFiNetwork wifiNetwork;

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
