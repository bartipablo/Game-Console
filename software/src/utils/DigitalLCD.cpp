#include "DigitalLCD.h"

Arduino_ILI9341* DigitalLCD::digitalLCD_ = nullptr;

void DigitalLCD::init(Arduino_ESP32SPI* bus, int TFT_RESET) {
  if (digitalLCD_ != nullptr) {
      return;
  }
  digitalLCD_ = new Arduino_ILI9341(bus, TFT_RESET);
}

Arduino_ILI9341* DigitalLCD::getInstance() {
  return digitalLCD_;
}