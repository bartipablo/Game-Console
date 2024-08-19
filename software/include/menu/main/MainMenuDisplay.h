#ifndef MainMenuDisplay_H
#define MainMenuDisplay_H

#include <string>

#include "DigitalLCD.h"
#include "Color.h"
#include "Icon.h"

/**
 * Methods for display of the main menu.
 */
namespace mainmenudisplay {
/**
 * Draws the application icon on the screen.
 * @param icon the icon to draw.
 */
void drawIcon(Icon& icon);

/**
 * Draws the title of the application on the screen.
 * @param title the title to draw.
 */
void drawTitle(const std::string& title);

/**
 * Draws the button info on the screen.
 * The button info is displayed at the bottom of the screen.
 */
void drawButtonInfo();

}

#endif