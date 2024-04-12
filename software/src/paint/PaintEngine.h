#ifndef PaintEngine_H
#define PaintEngine_H

#include "Arduino.h"
#include "Canvas.h"
#include "PaintDisplay.h"
#include "ColorBox.h"
#include "../utils/UserInput.h"
#include "../cursor/Cursor.h"
#include "../cursor/CursorDisplay.h"
#include "../cursor/shapes/WindowsArrow.h"
#include "../common/Color.h"
#include "../utils/InputBlocking.h"

class PaintEngine {

public:
    PaintEngine();

    ~PaintEngine();

    void run();

private:
    Canvas* canvas;

    Cursor* cursor;

    PaintDisplay* paintDisplay;

    CursorDisplay* cursorDisplay;

    ColorBox* colorBox;

    InputBlocking* inputBlocking;

    UserInput* userInput = UserInput::getInstance();

    bool shutdown;

    void runColorSelection();
};


#endif