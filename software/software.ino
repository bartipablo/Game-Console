#include <Arduino_GFX_Library.h>

#include "./src/utils/DigitalLCD.h"
#include "./src/main-menu/MainMenu.h"
#include "./src/utils/wifi/WiFiConnection.h"


#define TFT_SCK 18  // CLK
#define TFT_MOSI 23 // DIN
#define TFT_MISO -1
#define TFT_CS 22
#define TFT_DC 21
#define TFT_RESET 17
#define LEFT_BUTTON 4
#define RIGHT_BUTTON 15
#define JOYSTIC_X 34
#define JOYSTIC_Y 39
#define JOYSTIC_BUTTON 32

#define DISPLAY_ROTATION 3

void setup() {

    UserInput::init(LEFT_BUTTON, RIGHT_BUTTON, JOYSTIC_X, JOYSTIC_Y, JOYSTIC_BUTTON);

    WiFiConnection::init();

    Arduino_ESP32SPI bus = Arduino_ESP32SPI(TFT_DC, TFT_CS, TFT_SCK, TFT_MOSI, TFT_MISO);

    DigitalLCD::init(&bus, TFT_RESET);

    Arduino_ILI9341* display = DigitalLCD::getInstance();
    display->begin();
    display->setRotation(DISPLAY_ROTATION);

    MainMenu* menu = new MainMenu();
    menu->start();

    delete menu;
}

    

void loop() {}
