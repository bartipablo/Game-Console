#ifndef AppMenu_H
#define AppMenu_H

#include <vector>
#include "Arduino.h"

#include "App.h"
#include "InputBlocking.h"
#include "UserInput.h"

/**
 * Represents a menu that displays a list of applications.
 */
class AppMenu {
public:
/**
 * Creates a new AppMenu.
 * @param apps the list of applications to display in the menu.
 * The applications will be displayed in the order they are in the list.
 */
    AppMenu(std::vector<App*> apps);

    ~AppMenu();

/**
 * Sets whether the menu should be looped or not.
 * If the menu is looped, the menu will loop through the applications when the user presses the next or previous button.
 * If the menu is not looped, the menu will not loop through the applications when the user presses the next or previous button.
 * @param loopedMenu true if the menu should be looped, false otherwise.
*/
    void setLoopedMenu(bool loopedMenu);

/**
 * Sets whether the menu should block the exit or not.
 * If the menu blocks the exit, the menu will not exit when the user presses the exit button.
 * If the menu does not block the exit, the menu will exit when the user presses the exit button.
 * @param blockExit true if the menu should block the exit, false otherwise.
 */
    void setBlockExit(bool blockExit);

/**
 * Sets whether the menu should exit automatically or not.
 * If the menu exits automatically, the menu will exit after the user has finished using the application.
 * If the menu does not exit automatically, the menu will not exit after the user has finished using the application.
 * @param autoExit true if the menu should exit automatically, false otherwise.
 */
    void setAutoExit(bool autoExit);

/**
 * run the menu.
 */
    void start();

private:
/**
 * Displays the previous application in the menu
*/
    void previousApplication();

/**
 * Displays the next application in the menu
 */ 
    void nextApplication();

    int currentApplicationIndex = 0;

    bool blockExit = false;

    bool loopedMenu = false;

    bool autoExit = false;

    InputBlocking* inputBlocking;

    UserInput* userInput;

    App* currentApplication;

    std::vector<App*> appList;
};

#endif