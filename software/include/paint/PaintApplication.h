#ifndef PaintApplication_H
#define PaintApplication_H

#include <string>

#include "App.h" 
#include "MainMenuDisplay.h"
#include "PaintIcon.h"
#include "PaintEngine.h"

class PaintApplication : public App {
public:
    PaintApplication(MainMenuDisplay* menuDisplay) {
        title = "Paint";
        this->menuDisplay = menuDisplay;
    }

    void start() override {
        PaintEngine* paintEngine = new PaintEngine();
        paintEngine->run();
        delete paintEngine;
    }

    void display() override {
        Icon* paintIcon = new PaintIcon();

        menuDisplay->clear();
        menuDisplay->drawIcon(*paintIcon);
        menuDisplay->drawTitle(title);
        menuDisplay->drawButtonInfo();

        delete paintIcon;
    }

private:
    std::string title;

    MainMenuDisplay* menuDisplay;  

};

#endif