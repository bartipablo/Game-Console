#ifndef NotepadApplication_H
#define NotepadApplication_H

#include <string>

#include "App.h" 
#include "MainMenuDisplay.h"
#include "NotepadIcon.h"
#include "NotepadEngine.h"

class NotepadApplication : public App {
public:
    NotepadApplication(MainMenuDisplay* menuDisplay) {
        title = "Notepad";
        this->menuDisplay = menuDisplay;
    }

    void start() override {
        NotepadEngine* notepadEngine = new NotepadEngine();
        notepadEngine->run();
        delete notepadEngine;
    }

    void display() override {
        Icon* notepadIcon = new NotepadIcon();

        menuDisplay->clear();
        menuDisplay->drawIcon(*notepadIcon);
        menuDisplay->drawTitle(title);
        menuDisplay->drawButtonInfo();

        delete notepadIcon;
    }

private:
    std::string title;

    MainMenuDisplay* menuDisplay;  
};

#endif
