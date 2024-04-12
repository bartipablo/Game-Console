#ifndef NotepadDisplay_H
#define NotepadDisplay_H

#include "../utils/DigitalLCD.h"
#include "../common/Color.h"

class NotepadDisplay {

public:
    void drawRows(std::string* rows, int rowsQuantity);


private:
    Arduino_ILI9341* display = DigitalLCD::getInstance();
};


#endif