#ifndef AppDisplay_H
#define AppDisplay_H

#include "App.h"

/**
 * @brief Class responsible for displaying the application/option on the screen.
 * 
 */
class AppDisplay {
public:
    virtual void display(App& app) = 0;
};

#endif