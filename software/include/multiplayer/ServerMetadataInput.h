#ifndef ServerMetadataInput_H
#define ServerMetadataInput_H

#include <string>
#include <regex>
#include <cstring>

#include "BasicDisplay.h"

#include "UserInput.h"
#include "InputBlocking.h"
#include "WiFiConnection.h"

#include "Keyboard.h"
#include "KeyboardDisplay.h"
#include "KeyboardFactory.h"
#include "StandardKeyboardService.h"

#include "ServerMetadataInputDisplay.h"

namespace servermetadatain {

/**
 * represents which data is currently being entered.
*/
enum class ActualInput {
    SERVER_IPv4,
    SERVER_PORT
};


/**
 * Class that provides an interface for server input: IPv4 and port.
*/
class ServerMetadataInput {
public:
    ServerMetadataInput();

    /**
     * function starts the whole procedure of entering the IP and port of the server. 
     * It provides an interactive and graphical interface. It will be terminated after data entry or cancellation.
    */
    void start();

    /**
     * Function that should be called after start.
     * @return server IPv4 string provided by user if entered correctly.
     * @return unspecified string otherwise.
    */
    std::string getServerIPv4() const {
        return serverIPv4;
    }

    /**
     * Function that should be called after start.
     * @return server port provided by user if entered correctly.
     * @return 0 otherwise (also when the user cancels the procedure).
    */
    int getServerPort() const {
        return serverPort;
    }

    /**
     * Function that should be called after start.
     * @return true if the data entered is syntactically correct.
     * @return false otherwise (also when the user cancels the procedure).
    */
    bool isCorrectInputProvided() const {
        return correctInputProvided;
    }

private:
    InputBlocking inputBlocking;

    keyboard::Keyboard keyboard;

    wifi::WiFiConnection* wifiConnection = wifi::WiFiConnection::getInstance();

    /**
     * Server pressed key.
     * Function blocking invalid chars for port and IPv4.
    */
    void serveKey(keyboard::Key key);

    /**
     * Display message about invalid data
    */
    void invalidInputCommunicate(int time, std::string message);

    /**
     * Display message about no wifi connection.
    */
    void noWifiConnected();

    UserInput* userInput = UserInput::getInstance();

    // data provided by user --------------------------
    ActualInput actualInput = ActualInput::SERVER_IPv4;

    /**
     * The main function where the user enters metadata.
    */
    void readServerMetadata();

    std::string serverIPv4;

    std::string serverPortStr;

    int serverPort;
    // data provided by user --------------------------

    // states -----------------------------------------
    bool inputIPv4AndPort = true;

    bool shutdown = false;

    bool correctInputProvided = false;
    // states -----------------------------------------
};


/**
 * Check if the IP entered by the user is correct. 
*/
bool isValidIPv4(const std::string& str);

/**
 * Check if the port entered by the user is correct. 
*/
bool isValidPort(const std::string& portStr);

bool isAvailableCharForIPv4(char c);

bool isAvailableCharForPort(char c);


}

#endif