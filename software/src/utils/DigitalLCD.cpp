#include "DigitalLCD.h"

Arduino_ILI9341* DigitalLCD::digitalLCD_ = nullptr;

void DigitalLCD::init(const Arduino_ESP32SPI* bus, int TFT_RESET, int defaultRotation) {
  if (digitalLCD_ != nullptr) {
      return;
  }
  digitalLCD_ = new Arduino_ILI9341(const_cast<Arduino_ESP32SPI*>(bus), TFT_RESET);
  digitalLCD_->begin();
  digitalLCD_->setRotation(defaultRotation);
}


Arduino_ILI9341* DigitalLCD::getInstance() {
  return digitalLCD_;
}