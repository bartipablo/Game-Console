#include "PaintEngine.h"

PaintEngine::PaintEngine() {
    this->canvas = new Canvas();
    this->paintDisplay = new PaintDisplay();
    this->cursor = new Cursor(WindowsArrow());
    this->cursorDisplay = new CursorDisplay(*this->cursor);

    this->shutdown = false;

}

PaintEngine::~PaintEngine() {
    delete this->canvas;
    delete this->paintDisplay;
    delete this->cursor;
    delete this->cursorDisplay;
}

//TODO
void PaintEngine::run() {
    cursor->setSensitive(50);

    paintDisplay->drawCanvas(*canvas);

    while(!shutdown) {
        delay(50);
        
        if (userInput->isPressedLeftButton()) {
            canvas->drawPixel(cursor->getPosition(), selectedColor);
        }

        if (userInput->isPressedRightButton()) {
            canvas->clear();
            paintDisplay->drawCanvas(*canvas);
        }
        
        paintDisplay->drawCanvasPart(*canvas, cursor->getPosition(), cursor->getCursorShape().getWidthPx(), cursor->getCursorShape().getHeightPx());

        cursor->move(userInput->getXJoysticVal(), userInput->getYJoysticVal());

        cursorDisplay->drawCursor();
    }
}

