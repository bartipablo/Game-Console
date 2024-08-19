#ifndef NotepadApplication_H
#define NotepadApplication_H

#include <string>

#include "BasicDisplay.h"
#include "App.h" 
#include "MainMenuDisplay.h"
#include "NotepadIcon.h"
#include "NotepadEngine.h"

class NotepadApplication : public App {
public:
    NotepadApplication() : title {"Notepad"} {};

    void start() override;

    void display() override;

private:
    std::string title;
};

#endif
