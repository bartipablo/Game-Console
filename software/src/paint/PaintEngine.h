#ifndef PaintEngine_H
#define PaintEngine_H

#include "Arduino.h"
#include "Canvas.h"
#include "PaintDisplay.h"
#include "../UserInput.h"
#include "../cursor/Cursor.h"
#include "../cursor/CursorDisplay.h"
#include "../cursor/shapes/WindowsArrow.h"
#include "../Color.h"

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

    UserInput* userInput = UserInput::getInstance();

    bool shutdown;

    int selectedColor = Color::GREEN_;
};


#endif