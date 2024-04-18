#ifndef MainMenuDisplay_H
#define MainMenuDisplay_H

#include <string>

#include "../utils/DigitalLCD.h"
#include "../common/Color.h"
#include "../common/Icon.h"

class MainMenuDisplay {

public:
/**
 * Clears the screen.
*/
    void clear();

/**
 * Draws the application icon on the screen.
 * @param icon the icon to draw.
 */
    void drawIcon(Icon& icon);


/**
 * Draws the title of the application on the screen.
 * @param title the title to draw.
 */
    void drawTitle(std::string title);

/**
 * Draws the button info on the screen.
 * The button info is displayed at the bottom of the screen.
 */
    void drawButtonInfo();

private:
    Arduino_ILI9341* display = DigitalLCD::getInstance();
};

#endif