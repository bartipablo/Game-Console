#include "Canvas.h"

Canvas::Canvas() {
    pixels = new int*[height];

    for (int i = 0; i < height; ++i) {
        pixels[i] = new int[width];
    }

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            pixels[y][x] = Color::WHITE_;
        }
    }
}

Canvas::~Canvas() {
    for (int i = 0; i < height; ++i) {
        delete[] pixels[i];
    }
    delete[] pixels;
}

int** Canvas::getPixels() {
    return pixels;
}

int Canvas::getWidth() {
    return width;
}

int Canvas::getHeight() {
    return height;
}

int Canvas::getPixelSize() {
    return pixelSize;
}

void Canvas::drawPixel(Vector2D cursorPosition, int color) {
    int x = cursorPosition.x() / 5;
    int y = cursorPosition.y() / 5;

    if (x < 0 || x >= width || y < 0 || y >= height) {
        return;
    }

    pixels[y][x] = color;
}

void Canvas::clear() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            pixels[y][x] = Color::WHITE_;
        }
    }
}