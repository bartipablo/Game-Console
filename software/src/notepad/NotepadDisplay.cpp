#include "NotepadDisplay.h"

void NotepadDisplay::drawRows(std::string* rows, int rowsQuantity) {
    display->fillRect(0, 0, 320, 140, Color::BLACK_);

    int y = 0;
    for (int i = 0; i <= rowsQuantity; i++) {
        display->setCursor(0, y);
        display->setTextColor(Color::WHITE_);
        display->setTextSize(1);
        display->print(rows[i].c_str());
        y += 8;
    }
}