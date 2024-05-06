#ifndef PongApplication_H
#define PongApplication_H

#include <string>
#include <regex>

#include "../../app-menu/App.h" 
#include "../../main-menu/MainMenuDisplay.h"
#include "PongIcon.h"
#include "../common/ServerMetadataInput.h"
#include "../pong-console/ConsoleClient.h"


class PongApplication : public App {
public:
    PongApplication(MainMenuDisplay* menuDisplay) {
        title = "Pong (Multi)";
        this->menuDisplay = menuDisplay;
    }

    void start() override {
        ServerMetadataInput* serverMetadataInput = new ServerMetadataInput();
        serverMetadataInput->start();

        std::string serverIPv4 = serverMetadataInput->getServerIPv4();
        int serverPort = serverMetadataInput->getServerPort();
        bool correctInputProvided = serverMetadataInput->isCorrectInputProvided();

        delete serverMetadataInput;

        if (correctInputProvided) {
            ConsoleClient* client = new ConsoleClient(serverIPv4, serverPort);
            client->start();
            delete client;
        }
    }

    void display() override {
        Icon* pongIcon = new PongIcon();

        menuDisplay->clear();
        menuDisplay->drawIcon(*pongIcon);
        menuDisplay->drawTitle(title);
        menuDisplay->drawButtonInfo();

        delete pongIcon;
    }

private:
    std::string title;

    MainMenuDisplay* menuDisplay;  

};

#endif