#ifndef Menu_H
#define Menu_H

#include <vector>
#include <memory>

#include "mymemory.h"
#include "AppMenu.h"
#include "TetrisApplication.h"
#include "PaintApplication.h"
#include "NotepadApplication.h"
#include "WiFiApplication.h"
#include "PongApplication.h"
#include "SnakeApplication.h"
#include "MainMenuDisplay.h"
#include "BatteryApplication.h"

/**
 * The main menu of the console.
 * The main menu allows the user to navigate between applications.
 * The user can select an application to start.
 * The user can navigate between applications using the arrow keys.
 * The user can start an application by pressing the enter key.
 */
class MainMenu {

public:
    MainMenu();

/**
 * Starts the main menu.
 * NOTE: This is where the user's control will begin when the console is launched!
 */
    void start();

private:
    std::unique_ptr<AppMenu> appMenu;
};

#endif