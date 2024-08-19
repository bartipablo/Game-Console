#include "Canvas.h"

namespace paint {


Canvas::Canvas() {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            pixels[y][x] = Color::WHITE_;
        }
    }
}

int* Canvas::getPixels() {
    return &pixels[0][0];
}

int Canvas::getWidth() const {
    return WIDTH;
}

int Canvas::getHeight() const {
    return HEIGHT;
}

int Canvas::getPixelSize() const {
    return PIXEL_SIZE;
}

void Canvas::drawPixel(Vector2D cursorPosition, int color) {
    int x = cursorPosition.x() / 5;
    int y = cursorPosition.y() / 5;

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return;
    }

    pixels[y][x] = color;
}

void Canvas::clear() {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            pixels[y][x] = Color::WHITE_;
        }
    }
}

}