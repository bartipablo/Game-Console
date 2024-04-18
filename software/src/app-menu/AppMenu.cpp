#include "AppMenu.h"

AppMenu::~AppMenu() {
    for (App* app : appList) {
        delete app;
    }
    delete appDisplay;
    delete inputBlocking;
}

void AppMenu::setLoopedMenu(bool loopedMenu) {
    this->loopedMenu = loopedMenu;
}

void AppMenu::setBlockExit(bool blockExit) {
    this->blockExit = blockExit;
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

    appDisplay->display(*currentApplication);

    while (true) {
        delay(20);
        if (inputBlocking->isBlocked()) {
            inputBlocking->decrement();
            continue;
        }

        if (userInput->isPressedJoysticLeft()) {
            previousApplication();
            appDisplay->display(*currentApplication);
            inputBlocking->startBlocking(10);
        }

        if (userInput->isPressedJoysticRight()) {
            nextApplication();
            appDisplay->display(*currentApplication);
            inputBlocking->startBlocking(10);
        }

        if (userInput->isPressedLeftButton()) {
            currentApplication->start();
            appDisplay->display(*currentApplication);
            inputBlocking->startBlocking(20);
        }

        if (userInput->isPressedRightButton()) {
            inputBlocking->startBlocking(20);
            return;
        }
    }
}