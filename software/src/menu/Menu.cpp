#include "Menu.h"


Menu::Menu() {
    menuDisplay = new MenuDisplay();
    inputBlocking = new InputBlocking();

    applications.push_back(new TetrisApplication());
    applications.push_back(new PaintApplication());

    applicationsQuantity = applications.size();
    currentApplicationIndex = 0;
    currentApplication = applications[currentApplicationIndex];
}

Menu::~Menu() {
    delete menuDisplay;
    delete inputBlocking;

    for (int i = 0; i < applicationsQuantity; i++) {
        delete applications[i];
    }
}


void Menu::displayApplication(Application* application) {
    Icon* icon = application->getIcon();

    menuDisplay->clear();
    menuDisplay->drawIcon(*icon);
    menuDisplay->drawTitle(application->getTitle());
    menuDisplay->drawButtonInfo();

    delete icon;
}

void Menu::nextApplication() {
    currentApplicationIndex++;
    if (currentApplicationIndex >= applicationsQuantity || currentApplicationIndex < 0) {
        currentApplicationIndex = 0;
    }

    currentApplication = applications[currentApplicationIndex];
}

void Menu::previousApplication() {
    currentApplicationIndex--;
    if (currentApplicationIndex >= applicationsQuantity || currentApplicationIndex < 0) {
        currentApplicationIndex = applicationsQuantity - 1;
    }

    currentApplication = applications[currentApplicationIndex];
}


// MAIN SYSTEM FUNCTION
void Menu::start() {
    displayApplication(currentApplication);

    while (true) {
        delay(20);
        if (inputBlocking->isBlocked()) {
            inputBlocking->decrement();
            continue;
        }

        if (userInput->isPressedJoysticLeft()) {
            previousApplication();
            displayApplication(currentApplication);
            inputBlocking->startBlocking(10);
        }

        if (userInput->isPressedJoysticRight()) {
            nextApplication();
            displayApplication(currentApplication);
            inputBlocking->startBlocking(10);
        }

        if (userInput->isPressedLeftButton()) {
            currentApplication->start();
            displayApplication(currentApplication);
            inputBlocking->startBlocking(40);
        }
    }
}