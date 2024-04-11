#include "PaintDisplay.h"

PaintDisplay::PaintDisplay() {}

void PaintDisplay::drawCanvas(Canvas& canvas) {

    int** pixels = canvas.getPixels();
    int width = canvas.getWidth();
    int height = canvas.getHeight();
    int pixelSize = canvas.getPixelSize();

    uint8_t originalRotation = display->getRotation();
    display->setRotation(3); 

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            display->fillRect(x * pixelSize, y * pixelSize, pixelSize, pixelSize, pixels[y][x]);
        }
    }

    display->setRotation(originalRotation);
}


void PaintDisplay::drawCanvasPart(Canvas& canvas, Vector2D position, int widthPx, int heightPx) {
    
    int** canvasPixels = canvas.getPixels();
    int canvasWidth = canvas.getWidth();
    int canvasHeight = canvas.getHeight();
    int canvasPixelSize = canvas.getPixelSize();

    int x = position.x() / 5;
    int y = position.y() / 5;
    int width = (widthPx / 5) + 2;
    int height = (heightPx / 5) + 2;

    uint8_t originalRotation = display->getRotation();
    display->setRotation(3);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (x + j < 0 || x + j >= canvasWidth || y + i < 0 || y + i >= canvasHeight) {
                continue;
            }
            display->fillRect((x + j) * canvasPixelSize, (y + i) * canvasPixelSize, canvasPixelSize, canvasPixelSize, canvasPixels[y + i][x + j]);
        }
    }
}