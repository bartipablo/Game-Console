#ifndef App_H
#define App_H


/**
 * @brief Class representing application/option in the AppMenu.
 */
class App {
public:
    /**
     * @brief Start the application.
     * Activated by pressing the left button.
     * when finished, return to menu.
     */
    virtual void start() = 0;

    /**
     * @brief Display the application preview/info on screen.
     * Activated when the option is selected
     */
    virtual void display() = 0;
};

#endif