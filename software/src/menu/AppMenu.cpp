#include "AppMenu.h"

AppMenu::AppMenu(std::vector<App*> apps) {
    appList = apps;
    inputBlocking = new InputBlocking();
    userInput = UserInput::getInstance();
}

AppMenu::~AppMenu() {
    for (App* app : appList) {
        delete app;
    }
    delete inputBlocking;
}

void AppMenu::setLoopedMenu(bool loopedMenu) {
    this->loopedMenu = loopedMenu;
}

void AppMenu::setBlockExit(bool blockExit) {
    this->blockExit = blockExit;
}

void AppMenu::setAutoExit(bool autoExit) {
    this->autoExit = autoExit;
}

void AppMenu::nextApplication() {
    currentApplicationIndex++;
    if (currentApplicationIndex >= appList.size() || currentApplicationIndex < 0) {
        if (loopedMenu) currentApplicationIndex = 0;
        else            currentApplicationIndex = appList.size() - 1;
    }
    currentApplication = appList[currentApplicationIndex];
}

void AppMenu::previousApplication() {
    currentApplicationIndex--;
    if (currentApplicationIndex >= appList.size() || currentApplicationIndex < 0) {
        if (loopedMenu) currentApplicationIndex = appList.size() - 1;
        else            currentApplicationIndex = 0;
    }
    currentApplication = appList[currentApplicationIndex];
}

void AppMenu::start() {
    if (appList.size() == 0) return;

    currentApplication = appList[currentApplicationIndex];

    currentApplication->display();
    inputBlocking->startBlocking(20);

    while (true) {
        delay(20);
        if (inputBlocking->isBlocked()) {
            inputBlocking->decrement();
            continue;
        }

        if (userInput->isPressedJoysticLeft()) {
            previousApplication();
            currentApplication->display();
            inputBlocking->startBlocking(10);
        }

        else if (userInput->isPressedJoysticRight()) {
            nextApplication();
            currentApplication->display();
            inputBlocking->startBlocking(10);
        }

        else if (userInput->isPressedLeftButton()) {
            currentApplication->start();
            if (autoExit) return;
            currentApplication->display();
            inputBlocking->startBlocking(20);
        }

        else if (userInput->isPressedRightButton() && !blockExit) {
            return;
        }
    }
}