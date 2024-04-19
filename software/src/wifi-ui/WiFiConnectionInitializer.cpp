#include "WiFiConnectionInitializer.h"

WiFiConnectionInitializer::WiFiConnectionInitializer(WiFiDisplay* display, WiFiNetwork wifiNetwork) 
    : wifiNetwork(wifiNetwork) {
    this->display = display;
    inputBlocking = new InputBlocking();
    keyboard = new Keyboard();
    keyboardDisplay = new KeyboardDisplay();
    wifiConnection = WiFiConnection::getInstance();
    userInput = UserInput::getInstance();
    shutdown = false;
}

WiFiConnectionInitializer::~WiFiConnectionInitializer() {
    delete inputBlocking;
    delete keyboard;
    delete keyboardDisplay;
}

void WiFiConnectionInitializer::run() {
    WiFiEncriptionType encriptionType = wifiNetwork.getEncryptionType();

    if (encriptionType == WiFiEncriptionType::WEP) {
        display->displayWEPInformation();
        delay(2000);
        return;
    }

    inputBlocking->startBlocking(20);

    display->clear();
    display->displayPassword(password);
    keyboardDisplay->drawKeys(keyboard->getKeys());
    keyboardDisplay->drawSelectedKey(keyboard->getCurrentKey());

    while (!shutdown) {
        delay(20);
        
        if (!inputBlocking->isBlocked()) {

            Key previousKey = keyboard->getCurrentKey();

            if (userInput->isPressedJoysticUp()) {
                keyboard->cursorUp();
                updateKey(previousKey, keyboard->getCurrentKey());
            }
            else if (userInput->isPressedJoysticDown()) {
                keyboard->cursorDown();
                updateKey(previousKey, keyboard->getCurrentKey());
            }
            else if (userInput->isPressedJoysticLeft()) {
                keyboard->cursorLeft();
                updateKey(previousKey, keyboard->getCurrentKey());
            }
            else if (userInput->isPressedJoysticRight()) {
                keyboard->cursorRight();
                updateKey(previousKey, keyboard->getCurrentKey());
            }
            else if (userInput->isPressedLeftButton()) {
                serveKey(keyboard->getCurrentKey());
            }
            else if (userInput->isPressedRightButton()) {
                return;
            }
        }
        inputBlocking->decrement();
            
    }
}

void WiFiConnectionInitializer::updateKey(Key previousKey, Key currentKey) {
    keyboardDisplay->drawKey(previousKey);
    keyboardDisplay->drawSelectedKey(currentKey);
    inputBlocking->startBlocking(10);
}

void WiFiConnectionInitializer::serveKey(Key key) {
    if (key.getCharacter() == 7) {
        keyboard->changeCapitalization();
        keyboardDisplay->drawKeys(keyboard->getKeys());
        keyboardDisplay->drawSelectedKey(keyboard->getCurrentKey());
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

    inputBlocking->startBlocking(10);
}