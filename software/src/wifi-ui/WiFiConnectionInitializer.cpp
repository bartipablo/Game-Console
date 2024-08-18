#include "WiFiConnectionInitializer.h"

WiFiConnectionInitializer::WiFiConnectionInitializer(WiFiDisplay* display, wifi::WiFiNetwork wifiNetwork) 
    : wifiNetwork(wifiNetwork) {
    this->display = display;
    inputBlocking = new InputBlocking();
    keyboardFactory = new KeyboardFactory();
    keyboard = keyboardFactory->createClassicKeyboard();
    keyboardDisplay = new KeyboardDisplay();
    standardKeyboardService = new StandardKeyboardService(keyboard, keyboardDisplay);
    wifiConnection = wifi::WiFiConnection::getInstance();
    userInput = UserInput::getInstance();
    shutdown = false;
}

WiFiConnectionInitializer::~WiFiConnectionInitializer() {
    delete inputBlocking;
    delete keyboardFactory;
    delete keyboard;
    delete keyboardDisplay;
    delete standardKeyboardService;
}

void WiFiConnectionInitializer::run() {
    wifi::WiFiEncriptionType encriptionType = wifiNetwork.getEncryptionType();

    if (encriptionType == wifi::WiFiEncriptionType::WEP) {
        display->displayWEPInformation();
        delay(2000);
        return;
    }

    inputBlocking->startBlocking(20);
    standardKeyboardService->registerInputBlocking(inputBlocking, 10);

    display->clear();
    display->displayPassword(password);
    standardKeyboardService->displayKeyboard();

    while (!shutdown) {
        delay(20);
        
        if (!inputBlocking->isBlocked()) {
            standardKeyboardService->serveUserInteraction();

            if (userInput->isPressedLeftButton()) {
                serveKey(keyboard->getCurrentKey());
            }
            else if (userInput->isPressedRightButton()) {
                return;
            }
        }
        inputBlocking->decrement();
            
    }
}

void WiFiConnectionInitializer::serveKey(Key key) {
    if (key.getCharacter() == CAPS_LOCK) {
        // ignore this case.
    }
    else if (key.getCharacter() == '\b') {
        if (password.length() > 0) {
            password.pop_back();
            display->displayPassword(password);
        }
    }
    else if (key.getCharacter() == '\n') {
        wifiConnection->connectToWiFi(wifiNetwork.getSSID(), password.c_str());
        shutdown = true;
        return;
    }
    else if (password.length() < 64) {
        password += key.getCharacter();
        display->displayPassword(password);
    }
}