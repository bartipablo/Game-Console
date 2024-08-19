#include "PaintEngine.h"

namespace paint {

PaintEngine::PaintEngine() : cursor {cursor::WindowsArrow{}}, shutdown {false} {}


void PaintEngine::run() {
    using namespace paintdisplay;

    cursor.setSensitive(50);

    drawCanvas(canvas);
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
            canvas.drawPixel(cursor.getPosition(), colorBox.getSelectedColor().getColorRGB565());
        }

        if (userInput->isPressedRightButton() && !userInput->isPressedJoysticButton()) {
            runColorSelection();
            drawCanvas(canvas);
        }
        
        drawCanvasPart(canvas, cursor.getPosition(), cursor.getCursorShape().getWidthPx(), cursor.getCursorShape().getHeightPx());

        cursor.move(userInput->getXJoysticVal(), userInput->getYJoysticVal());

        cursor::drawCursor(cursor);
    }
}


void PaintEngine::runColorSelection() {
    using namespace paintdisplay;

    drawColorBox(colorBox);
    inputBlocking.startBlocking(10);

    while (true) {
        delay(20);
        if (!inputBlocking.isBlocked()) {
            
            if (userInput->isPressedJoysticLeft()) {
                colorBox.previousColor();
                drawColorBox(colorBox);
                inputBlocking.startBlocking(10);

            }
            else if (userInput->isPressedJoysticRight()) {
                colorBox.nextColor();
                drawColorBox(colorBox);
                inputBlocking.startBlocking(10);
            }
            else if (userInput->isPressedLeftButton()) {
                colorBox.selectColor();
                delay(20);
                return;
            }
            else if (userInput->isPressedRightButton()) {
                delay(20);
                return;
            }
        }
        inputBlocking.decrement();
    }
}

}