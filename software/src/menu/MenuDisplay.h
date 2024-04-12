#ifndef MenuDisplay_H
#define MenuDisplay_H

#include <string>

#include "../utils/DigitalLCD.h"
#include "../common/Color.h"
#include "Icon.h"

class MenuDisplay {

public:
    void clear();

    void drawIcon(Icon& icon);

    void drawTitle(std::string title);

    void drawButtonInfo();

private:
    Arduino_ILI9341* display = DigitalLCD::getInstance();
};

#endif