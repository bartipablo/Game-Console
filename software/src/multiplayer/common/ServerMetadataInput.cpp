#include "ServerMetadataInput.h"

ServerMetadataInput::ServerMetadataInput() {
    display = new ServerMetadataInputDisplay();
    inputBlocking = new InputBlocking();
    basicDisplay = new BasicDisplay();
    keyboardFactory = new KeyboardFactory();
    keyboardDisplay = new KeyboardDisplay();
    keyboard = keyboardFactory->createClassicKeyboard();
    standardKeyboardService = new StandardKeyboardService(keyboard, keyboardDisplay);
}


ServerMetadataInput::~ServerMetadataInput() {
    delete display;
    delete inputBlocking;
    delete basicDisplay;
    delete keyboardFactory;
    delete keyboardDisplay;
    delete keyboard;
    delete standardKeyboardService;
}	


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

    inputBlocking->startBlocking(10);
    display->clearScreen();
    display->drawIPv4AndPortInputInfo(Color(Color::RED_), Color(Color::WHITE_));
    standardKeyboardService->displayKeyboard();
    standardKeyboardService->registerInputBlocking(inputBlocking, 10);

    while (inputIPv4AndPort) {
        delay(20);
        
        if (!inputBlocking->isBlocked()) {
            standardKeyboardService->serveUserInteraction();

            if (userInput->isPressedLeftButton()) {
                serveKey(keyboard->getCurrentKey());
            }
            else if (userInput->isPressedRightButton()) {
                inputIPv4AndPort = false;
                shutdown = true;
                break;
            }
        }
        inputBlocking->decrement();
    }
}


void ServerMetadataInput::serveKey(Key key) {
    if (key.getCharacter() == CAPS_LOCK) {
        // ignore this case.
    }

    // normal character
    else if (actualInput == SERVER_IPv4 && isAvailableCharForIPv4(key.getCharacter())) {
        if (serverIPv4.length() == 15) return;
        serverIPv4 += key.getCharacter();
        display->drawInputIPv4(serverIPv4);
    }
    else if (actualInput == SERVER_PORT && isAvailableCharForPort(key.getCharacter())) {
        if (serverPortStr.length() == 5) return;
        serverPortStr += key.getCharacter();
        display->drawInputPort(serverPortStr);
    }

    // backspace
    else if (key.getCharacter() == '\b') {
        if (actualInput == SERVER_IPv4 && serverIPv4.length() > 0) {
            serverIPv4.pop_back();
            display->drawInputIPv4(serverIPv4);
        }
        else if (actualInput == SERVER_PORT && serverPortStr.length() > 0) {
            serverPortStr.pop_back();
            display->drawInputPort(serverPortStr);
        }
    }

    //enter
    else if (key.getCharacter() == '\n') {
        if (actualInput == SERVER_IPv4) {
            display->drawIPv4AndPortInputInfo(Color(Color::WHITE_), Color(Color::RED_));
            actualInput = SERVER_PORT;
        }
        else if (actualInput == SERVER_PORT) {
            inputIPv4AndPort = false;
        }
    }
}


bool ServerMetadataInput::isAvailableCharForIPv4(char c) {
    return (c >= '0' && c <= '9') || c == '.';
}


bool ServerMetadataInput::isAvailableCharForPort(char c) {
    return c >= '0' && c <= '9';
}


bool ServerMetadataInput::isValidIPv4(const std::string& str) {
    std::regex pattern("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");

    return std::regex_match(str, pattern);
}


bool ServerMetadataInput::isValidPort(const std::string& portStr) {
    try {
        int port = atoi(portStr.c_str());
        return (port > 0 && port <= 65535);
    } catch (...) {
        return false;
    }
}


void ServerMetadataInput::invalidInputCommunicate(int time, std::string message) {
        correctInputProvided = false;
        basicDisplay->clearScreen();
        basicDisplay->drawInfo(message, "Error", Color::WHITE_, Color::RED_);
        delay(time);
}


void ServerMetadataInput::noWifiConnected() {
    basicDisplay->clearScreen();
    basicDisplay->drawInfo("You need to be connected to a wifi network", "Info", Color::WHITE_, Color::YELLOW_);
    delay(5000);
}