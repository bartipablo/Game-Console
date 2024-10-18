#include <Arduino.h>
#include <Wire.h>


#include "DigitalLCD.h"
#include "MainMenu.h"
#include "WiFiConnection.h"
#include "UserInput.h"
#include "Battery.h"


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
    constexpr int JOYSTIC_BUTTON {35};

    constexpr int I2C_SDA {32};
    constexpr int I2C_SCL {33};

    constexpr int BATTERY_THERMISTOR_B {3950};
    constexpr int DISPLAY_ROTATION {3};

    const Arduino_ESP32SPI bus { Arduino_ESP32SPI(TFT_DC, TFT_CS, TFT_SCK, TFT_MOSI, TFT_MISO) };
}


void setup() {
    using namespace Peripheral;

    Wire.begin(I2C_SDA, I2C_SCL);

    Battery::init(BATTERY_THERMISTOR_B, LC709203F_APA_500MAH);

    UserInput::init(LEFT_BUTTON, RIGHT_BUTTON, JOYSTIC_X, JOYSTIC_Y, JOYSTIC_BUTTON);

    wifi::WiFiConnection::init();

    DigitalLCD::init(&bus, TFT_RESET);
}

    

void loop() {
    MainMenu menu {};
    menu.start();
}
