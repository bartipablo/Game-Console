#include "ServerMetadataInput.h"

namespace servermetadatain {


ServerMetadataInput::ServerMetadataInput()
: keyboard{keyboard::KeyboardFactory::createClassicKeyboard()} {}


void ServerMetadataInput::start() {
    if (!wifiConnection->isConnected()) {
        noWifiConnected();
        return;
    }

    readServerMetadata();
    if (shutdown) {
        return;
    }
    else if (serverIPv4.empty() || serverPortStr.empty()) {
        invalidInputCommunicate(5000, "IPv4 and port cannot be empty.");
    }
    else if (!isValidIPv4(serverIPv4)) {
        invalidInputCommunicate(5000, "Invalid server IPv4.");
    }
    else if (!isValidPort(serverPortStr)) {
        invalidInputCommunicate(5000, "Invalid server port.");
    }
    else {
        // valid input.
        serverPort = std::stoi(serverPortStr);
        correctInputProvided = true;
    }
}


void ServerMetadataInput::readServerMetadata() {
    inputBlocking.startBlocking(10);
    basicdisplay::clearScreen();
    drawIPv4AndPortInputInfo(Color(Color::RED_), Color(Color::WHITE_));

    keyboard::StandardKeyboardService standardKeyboardService {keyboard};

    standardKeyboardService.displayKeyboard();
    standardKeyboardService.registerInputBlocking(&inputBlocking, 10);

    while (inputIPv4AndPort) {
        delay(20);
        
        if (!inputBlocking.isBlocked()) {
            standardKeyboardService.serveUserInteraction();

            if (userInput->isPressedLeftButton()) {
                serveKey(keyboard.getCurrentKey());
            }
            else if (userInput->isPressedRightButton()) {
                inputIPv4AndPort = false;
                shutdown = true;
                break;
            }
        }
        inputBlocking.decrement();
    }
}


void ServerMetadataInput::serveKey(keyboard::Key key) {
    using keyboard::CAPS_LOCK;

    if (key.getCharacter() == CAPS_LOCK) {
        // ignore this case.
    }

    // normal character
    else if (actualInput == ActualInput::SERVER_IPv4 && isAvailableCharForIPv4(key.getCharacter())) {
        if (serverIPv4.length() == 15) return;
        serverIPv4 += key.getCharacter();
        drawInputIPv4(serverIPv4);
    }
    else if (actualInput == ActualInput::SERVER_PORT && isAvailableCharForPort(key.getCharacter())) {
        if (serverPortStr.length() == 5) return;
        serverPortStr += key.getCharacter();
        drawInputPort(serverPortStr);
    }

    // backspace
    else if (key.getCharacter() == '\b') {
        if (actualInput == ActualInput::SERVER_IPv4 && serverIPv4.length() > 0) {
            serverIPv4.pop_back();
            drawInputIPv4(serverIPv4);
        }
        else if (actualInput == ActualInput::SERVER_PORT && serverPortStr.length() > 0) {
            serverPortStr.pop_back();
            drawInputPort(serverPortStr);
        }
    }

    //enter
    else if (key.getCharacter() == '\n') {
        if (actualInput == ActualInput::SERVER_IPv4) {
            drawIPv4AndPortInputInfo(Color(Color::WHITE_), Color(Color::RED_));
            actualInput = ActualInput::SERVER_PORT;
        }
        else if (actualInput == ActualInput::SERVER_PORT) {
            inputIPv4AndPort = false;
        }
    }
}


void ServerMetadataInput::invalidInputCommunicate(int time, std::string message) {
        correctInputProvided = false;
        basicdisplay::clearScreen();
        basicdisplay::drawInfo(message, "Error", Color::WHITE_, Color::RED_);
        delay(time);
}


void ServerMetadataInput::noWifiConnected() {
    basicdisplay::clearScreen();
    basicdisplay::drawInfo("You need to be connected to a wifi network", "Info", Color::WHITE_, Color::YELLOW_);
    delay(5000);
}


bool isValidIPv4(const std::string& str) {
    std::regex pattern("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");

    return std::regex_match(str, pattern);
}


bool isValidPort(const std::string& portStr) {
    try {
        int port = atoi(portStr.c_str());
        return (port > 0 && port <= 65535);
    } catch (...) {
        return false;
    }
}


bool isAvailableCharForIPv4(char c) {
    return (c >= '0' && c <= '9') || c == '.';
}


bool isAvailableCharForPort(char c) {
    return c >= '0' && c <= '9';
}

}