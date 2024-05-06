#ifndef ServerMetadataInput_H
#define ServerMetadataInput_H

#include <string>
#include <regex>

#include "../../utils/UserInput.h"
#include "../../utils/InputBlocking.h"
#include "../../keyboard/Keyboard.h"
#include "../../keyboard/KeyboardDisplay.h"

#include "ServerMetadataInputDisplay.h"

enum ActualInput {
    SERVER_IPv4,
    SERVER_PORT
};


class ServerMetadataInput {
public:
    ServerMetadataInput();

    ~ServerMetadataInput();

    void start();

    std::string getServerIPv4() {
        return serverIPv4;
    }

    int getServerPort() {
        return serverPort;
    }

    bool isCorrectInputProvided() {
        return correctInputProvided;
    }

private:
    ServerMetadataInputDisplay* display;

    InputBlocking* inputBlocking;

    Keyboard* keyboard;

    KeyboardDisplay* keyboardDisplay;

    void updateKey(Key previousKey, Key currentKey);

    void serveKey(Key key);

    bool isValidIPv4(const std::string& str);

    void invalidInputCommunicate(int time, std::string message);

    bool isValidPort(const std::string& portStr);

    UserInput* userInput = UserInput::getInstance();

    // data provided by user --------------------------
    ActualInput actualInput = SERVER_IPv4;

    void readServerMetadata();

    std::string serverIPv4;

    std::string serverPortStr;

    int serverPort;

    bool isAvailableCharForIPv4(char c);

    bool isAvailableCharForPort(char c);
    // data provided by user --------------------------

    // states -----------------------------------------
    bool inputIPv4AndPort = true;

    bool shutdown = false;

    bool correctInputProvided = false;
    // states -----------------------------------------

};


#endif