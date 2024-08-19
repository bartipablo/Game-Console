#include "KeyboardDisplay.h"

namespace keyboarddisplay {


void drawKey(keyboard::Key key) {
    drawKey(key, Color::GRAY_);
}


void drawKeys(std::vector<keyboard::Key> keys) {
    for (keyboard::Key key : keys) {
        drawKey(key, Color::GRAY_);
    }
}


void drawSelectedKey(keyboard::Key key) {
    drawKey(key, Color::GREEN_);
}


void drawKey(keyboard::Key key, int color) {
    Arduino_ILI9341* display = DigitalLCD::getInstance();

    int x = getXPx(key.getPosition());
    int y = getYPx(key.getPosition());

    display->setTextSize(1);

    display->fillRect(y, x, key.getWidth() * KEY_WIDTH, KEY_HEIGHT, BLACK);
    display->fillRect(y + 1, x + 1, key.getWidth() * KEY_WIDTH - 2, KEY_HEIGHT - 2, color);

    display->setCursor(y + 16 * key.getWidth() - 3 * key.toString().length(), x + 16 - 8);
    display->setTextColor(WHITE);
    display->println(key.toString().c_str());
}


int getXPx(Vector2D position) {
    return KEY_HEIGHT * position.x() + 140;
}


int getYPx(Vector2D position) {
    return KEY_WIDTH * position.y();
}

}