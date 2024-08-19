#include "MainMenuDisplay.h"


namespace mainmenudisplay {


void drawIcon(Icon& icon) {
    Arduino_ILI9341* display = DigitalLCD::getInstance();

    int pixelSize = icon.getPixelSize();

    int xPosition = icon.getPosition().x();
    int yPosition = icon.getPosition().y();

    for (int y = 0; y < icon.getHeight(); y++) {
        for (int x = 0; x < icon.getWidth(); x++) {

            display->fillRect(
                xPosition + x * pixelSize, 
                yPosition + y * pixelSize, 
                pixelSize, pixelSize, 
                icon.getRGB565(y, x)
            );
        }
    }
}


void drawTitle(std::string title) {
    Arduino_ILI9341* display = DigitalLCD::getInstance();

    display->setTextSize(4);
    display->setTextColor(Color::WHITE_);
    display->setCursor(160 - title.length() * 12, 10);
    display->print(title.c_str());
}


void drawButtonInfo() {
    Arduino_ILI9341* display = DigitalLCD::getInstance();

    display->setTextSize(1);
    display->setTextColor(Color::WHITE_);
    display->setCursor(70, 240 - 20);
    display->print("Press left button to continue.");
}

}