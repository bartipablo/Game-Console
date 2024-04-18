#ifndef Menu_H
#define Menu_H

#include <vector>

#include "../app-menu/AppMenu.h"
#include "../tetris/TetrisApplication.h"
#include "../paint/PaintApplication.h"
#include "../notepad/NotepadApplication.h"
#include "MainMenuDisplay.h"

class MainMenu {

public:
    MainMenu();

    ~MainMenu();

    void start();

private:
    AppMenu* appMenu;

    MainMenuDisplay* menuDisplay;
};

#endif