#ifndef DigitalLCD_H
#define DigitalLCD_H

#include <Arduino_GFX_Library.h>
#include "Arduino.h"

/**
 * @brief Class representing a digital LCD display.
 * 
 * The DigitalLCD is wrapper for Arduino_ILI9341.
 * It follows the "Singleton" design pattern for Arduino_ILI9341.
 */
class DigitalLCD {
public:
    DigitalLCD(const DigitalLCD&) = delete;

    void operator=(const DigitalLCD&) = delete;

    /**
     * @brief Gets the singleton instance of the DigitalLCD class.
     * 
     * @return A pointer to the singleton instance of the DigitalLCD class.
     */
    static Arduino_ILI9341* getInstance();

    /**
     * @brief Initializes the digital LCD display.
     * 
     * The init method initializes the digital LCD display with the provided
     * SPI bus and reset pin.
     * 
     * @param bus Pointer to the SPI bus used by the LCD display.
     * @param TFT_RESET The GPIO pin number for the reset of the LCD display.
     */
    static void init(const Arduino_ESP32SPI* bus, int TFT_RESET, int defaultRotation=3);

    static const int X_BOUNDARY = 320;

    static const int Y_BOUNDARY = 240;

private:
	static Arduino_ILI9341* digitalLCD_;
};

#endif