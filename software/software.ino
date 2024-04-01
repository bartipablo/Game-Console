#include <Arduino_GFX_Library.h>

#include "./src/UserInput.h"
#include "./src/DigitalLCD.h"
#include "./src/tetris/TetrisEngine.h"


#define TFT_SCK 18  // CLK
#define TFT_MOSI 23 // DIN
#define TFT_MISO -1
#define TFT_CS 22
#define TFT_DC 21
#define TFT_RESET 17
#define LEFT_BUTTON 4
#define RIGHT_BUTTON 15
#define JOYSTIC_X 13
#define JOYSTIC_Y 12
#define JOYSTIC_BUTTON 14


void setup() {

    UserInput::init(LEFT_BUTTON, RIGHT_BUTTON, JOYSTIC_X, JOYSTIC_Y, JOYSTIC_BUTTON);

    Arduino_ESP32SPI bus = Arduino_ESP32SPI(TFT_DC, TFT_CS, TFT_SCK, TFT_MOSI, TFT_MISO);

    DigitalLCD::init(&bus, TFT_RESET);

    Arduino_ILI9341* display = DigitalLCD::getInstance();
    display->begin();

    while (true) {
        TetrisEngine* engine = new TetrisEngine();
        engine->run();
        delete engine;
    }
}


void loop() {}
