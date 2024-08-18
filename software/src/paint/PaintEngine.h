#ifndef PaintEngine_H
#define PaintEngine_H

#include "Arduino.h"
#include "Canvas.h"
#include "PaintDisplay.h"
#include "ColorBox.h"
#include "UserInput.h"
#include "../cursor/Cursor.h"
#include "../cursor/CursorDisplay.h"
#include "WindowsArrow.h"
#include "Color.h"
#include "../utils/InputBlocking.h"

class PaintEngine {

public:
    PaintEngine();

    ~PaintEngine();

    /**
     * Start the paint enigne.
     */
    void run();

private:
    Canvas* canvas;

    cursor::Cursor* cursor;

    PaintDisplay* paintDisplay;

    ColorBox* colorBox;

    InputBlocking* inputBlocking;

    UserInput* userInput = UserInput::getInstance();

    bool shutdown;

    void runColorSelection();
};


#endif