#ifndef App_H
#define App_H


/**
 * @brief Class representing application/option in the app list.
 * 
 */
class App {
public:
    virtual void start() = 0;

    virtual void display() = 0;
};

#endif