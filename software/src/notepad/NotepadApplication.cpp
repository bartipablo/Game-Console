#include "NotepadApplication.h"


void NotepadApplication::start() {
    NotepadEngine notepad {};
    notepad.run();
}


void NotepadApplication::display() {
    using namespace mainmenudisplay;
    using basicdisplay::clearScreen;

    NotepadIcon notepadIcon {};

    clearScreen();
    drawIcon(notepadIcon);
    drawTitle(title);
    drawButtonInfo();
}