#include "PaintEngine.h"

PaintEngine::PaintEngine() {
    this->canvas = new Canvas();
    this->paintDisplay = new PaintDisplay();
    this->cursor = new Cursor(WindowsArrow());
    this->cursorDisplay = new CursorDisplay(*this->cursor);
    this->colorBox = new ColorBox();
    this->inputBlocking = new InputBlocking();

    this->shutdown = false;
}

PaintEngine::~PaintEngine() {
    delete this->canvas;
    delete this->paintDisplay;
    delete this->cursor;
    delete this->cursorDisplay;
    delete this->colorBox;
    delete this->inputBlocking;
}


void PaintEngine::run() {
    cursor->setSensitive(50);

    paintDisplay->drawCanvas(*canvas);
    delay(300);

    while(!shutdown) {
        delay(50);

        if (userInput->isPressedLeftButton() && userInput->isPressedRightButton() && userInput->isPressedJoysticButton()) {
            delay(200);
            if (userInput->isPressedLeftButton() && userInput->isPressedRightButton() && userInput->isPressedJoysticButton()) {
                shutdown = true;
                break;
            }
        }

        if (userInput->isPressedLeftButton() && !userInput->isPressedJoysticButton()) {
            canvas->drawPixel(cursor->getPosition(), colorBox->getSelectedColor().getColorRGB565());
        }

        if (userInput->isPressedRightButton() && !userInput->isPressedJoysticButton()) {
            runColorSelection();
            paintDisplay->drawCanvas(*canvas);
        }
        
        paintDisplay->drawCanvasPart(*canvas, cursor->getPosition(), cursor->getCursorShape().getWidthPx(), cursor->getCursorShape().getHeightPx());

        cursor->move(userInput->getXJoysticVal(), userInput->getYJoysticVal());

        cursorDisplay->drawCursor();
    }
}


void PaintEngine::runColorSelection() {
    paintDisplay->drawColorBox(*colorBox);
    inputBlocking->startBlocking(10);

    while (true) {
        delay(20);
        if (!inputBlocking->isBlocked()) {
            
            if (userInput->isPressedJoysticLeft()) {
                colorBox->previousColor();
                paintDisplay->drawColorBox(*colorBox);
                inputBlocking->startBlocking(10);

            }
            else if (userInput->isPressedJoysticRight()) {
                colorBox->nextColor();
                paintDisplay->drawColorBox(*colorBox);
                inputBlocking->startBlocking(10);
            }
            else if (userInput->isPressedLeftButton()) {
                colorBox->selectColor();
                delay(20);
                return;
            }
            else if (userInput->isPressedRightButton()) {
                delay(20);
                return;
            }
        }
        inputBlocking->decrement();
    }
}

