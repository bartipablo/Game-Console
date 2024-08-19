#include "WindowsArrow.h"

namespace {
    const int WIDTH = 12;
    const int HEIGHT = 19;
}

namespace cursor {

const char WindowsArrow::arrowCharRepresentation[HEIGHT][WIDTH] = {
    {'1','0','0','0','0','0','0','0','0','0','0','0'},
    {'1','1','0','0','0','0','0','0','0','0','0','0'},
    {'1','2','1','0','0','0','0','0','0','0','0','0'},
    {'1','2','2','1','0','0','0','0','0','0','0','0'},
    {'1','2','2','2','1','0','0','0','0','0','0','0'},
    {'2','2','2','2','2','1','0','0','0','0','0','0'},
    {'1','2','2','2','2','2','1','0','0','0','0','0'},
    {'1','2','2','2','2','2','2','1','0','0','0','0'},
    {'1','2','2','2','2','2','2','2','1','0','0','0'},
    {'1','2','2','2','2','2','2','2','2','1','0','0'},
    {'1','2','2','2','2','2','2','2','2','2','1','0'},
    {'1','2','2','2','2','2','2','2','2','2','2','1'},
    {'1','2','2','2','2','2','2','2','1','1','1','0'},
    {'1','2','2','2','2','2','2','1','0','0','0','0'},
    {'1','2','2','2','1','2','2','2','1','0','0','0'},
    {'1','2','2','1','0','1','2','2','1','0','0','0'},
    {'1','2','1','0','0','0','1','2','2','1','0','0'},
    {'1','1','0','0','0','0','1','2','2','1','0','0'},
    {'0','0','0','0','0','0','0','1','1','0','0','0'}
};

WindowsArrow::WindowsArrow() : CursorShape{WIDTH, HEIGHT} {

    for (int y = 0; y < heightPx; y++) {
        for (int x = 0; x < widthPx; x++) {
            char c = arrowCharRepresentation[y][x];

            if (c == '1') {
                pixels.push_back(Pixel(Vector2D(x, y), Color::BLACK_));
            } 
            else if (c == '2') {
                pixels.push_back(Pixel(Vector2D(x, y), Color::WHITE_));
            }
        }
    }
}

}