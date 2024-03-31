#ifndef DigitalLCD_H
#define DigitalLCD_H

#include <Arduino_GFX_Library.h>
#include "Arduino.h"

class DigitalLCD {
public:
    DigitalLCD(const DigitalLCD&) = delete;

    void operator=(const DigitalLCD&) = delete;

    static Arduino_ILI9341* getInstance();

    static void init(Arduino_ESP32SPI* bus, int TFT_RESET);

private:

	static Arduino_ILI9341* digitalLCD_;
};

#endif