#include "WindowsArrow.h"

namespace cursor {

WindowsArrow::WindowsArrow() {

    this->widthPx = 12;
    this->heightPx = 19;

    for (int y = 0; y < 19; y++) {
        for (int x = 0; x < 12; x++) {
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