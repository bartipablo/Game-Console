#ifndef Menu_H
#define Menu_H

#include <vector>

#include "Application.h"
#include "./paint/PaintApplication.h"
#include "./tetris/TetrisApplication.h"
#include "./notepad/NotepadApplication.h"
#include "MenuDisplay.h"
#include "Icon.h"
#include "../utils/UserInput.h"
#include "../utils/InputBlocking.h"

class Menu {

public:
/**
 * Constructor of the Menu class.
 * Initializes application and utils.
*/
    Menu();

/**
 * Destructor of the Menu class.
 * Deletes application and utils.
 */
    ~Menu();

/**
 * Starts the main menu.
 * The main menu allows the user to navigate between applications.
 * The user can select an application to start.
 * The user can navigate between applications using the arrow keys.
 * The user can start an application by pressing the enter key.
 * NOTE: This is where the user's control will begin when the console is launched!
 */
    void start();

private:

    MenuDisplay* menuDisplay;

    UserInput* userInput = UserInput::getInstance();

    InputBlocking* inputBlocking;

    int currentApplicationIndex = 0;

    std::vector<Application*> applications;

    Application* currentApplication;

    int applicationsQuantity;
    
/**
 * set next application in menu as current application.
 * If the current application is the last one, the first application will be set as the current application.
 */
    void nextApplication();

/**
 * set previous application in menu as current application.
 * If the current application is the first one, the last application will be set as the current application.
 */
    void previousApplication();

/**
 * Display the application on the screen.
 * The application is displayed with its icon, title and button info.
 * @param application the application to display.
 */
    void displayApplication(Application* application);
};

#endif