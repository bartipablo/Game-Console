#include "MainMenuDisplay.h"

void MainMenuDisplay::clear() {
    display->fillScreen(Color::BLACK_);
}

void MainMenuDisplay::drawIcon(Icon& icon) {

    int pixelSize = icon.getPixelSize();

    int xPosition = icon.getPosition().x();
    int yPosition = icon.getPosition().y();

    uint8_t originalRotation = display->getRotation();
    display->setRotation(3); 

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

    display->setRotation(originalRotation);
}

void MainMenuDisplay::drawTitle(std::string title) {

    uint8_t originalRotation = display->getRotation();
    display->setRotation(3); 

    display->setTextSize(4);
    display->setTextColor(Color::WHITE_);
    display->setCursor(160 - title.length() * 12, 10);
    display->print(title.c_str());

    display->setRotation(originalRotation);
}

void MainMenuDisplay::drawButtonInfo() {

    uint8_t originalRotation = display->getRotation();
    display->setRotation(3); 

    display->setTextSize(1);
    display->setTextColor(Color::WHITE_);
    display->setCursor(70, 240 - 20);
    display->print("Press left button to continue.");

    display->setRotation(originalRotation);
}