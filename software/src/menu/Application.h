#ifndef Application_H
#define Application_H

#include <string>

#include "../common/Vector2D.h"
#include "Icon.h"

/**
 * Interface used in the console main menu.
 * Represents an application.
 */
class Application {

public:
/**
 * @return the title of the application.
 * The title is displayed in the main menu.
*/
    std::string getTitle() {
        return title;
    }

/**
 * Launches applications when the user presses a button.
 * Exiting the method takes you to the main menu.
*/
    virtual void start() = 0;

/**
 * @return the icon representing the application.
 * The icon is displayed in the main menu.
 */
    virtual Icon* getIcon() = 0;

protected:
    std::string title;
};

#endif