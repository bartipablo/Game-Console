#include <Arduino.h>

#include "./utils/DigitalLCD.h"
#include "./main-menu/MainMenu.h"
#include "./utils/wifi/WiFiConnection.h"
#include "UserInput.h"


namespace Peripheral {

    constexpr int TFT_SCK {18};  // CLK
    constexpr int TFT_MOSI {23}; // DIN
    constexpr int TFT_MISO {-1};
    constexpr int TFT_CS {22};
    constexpr int TFT_DC {21};
    constexpr int TFT_RESET {17};
    constexpr int LEFT_BUTTON {4};
    constexpr int RIGHT_BUTTON {15};
    constexpr int JOYSTIC_X {34};
    constexpr int JOYSTIC_Y {39};
    constexpr int JOYSTIC_BUTTON {32};

    constexpr int DISPLAY_ROTATION {3};

    const Arduino_ESP32SPI bus { Arduino_ESP32SPI(TFT_DC, TFT_CS, TFT_SCK, TFT_MOSI, TFT_MISO) };
}


void setup() {
    using namespace Peripheral;

    UserInput::init(LEFT_BUTTON, RIGHT_BUTTON, JOYSTIC_X, JOYSTIC_Y, JOYSTIC_BUTTON);

    WiFiConnection::init();

    DigitalLCD::init(&bus, TFT_RESET);
}

    

void loop() {
    MainMenu menu {};
    menu.start();
}
