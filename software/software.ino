#include <Arduino_GFX_Library.h>

#include "./src/UserInput.h"

#define TFT_SCK 18  // CLK
#define TFT_MOSI 23 // DIN
#define TFT_MISO -1
#define TFT_CS 22
#define TFT_DC 21
#define TFT_RESET 17
#define LEFT_BUTTON 15
#define RIGHT_BUTTON 4
#define JOYSTIC_X 13
#define JOYSTIC_Y 12
#define JOYSTIC_BUTTON 14


void setup()
{
    UserInput::init(LEFT_BUTTON, RIGHT_BUTTON, JOYSTIC_X, JOYSTIC_Y, JOYSTIC_BUTTON);



    Serial.begin(115200);

    Arduino_ESP32SPI bus = Arduino_ESP32SPI(TFT_DC, TFT_CS, TFT_SCK, TFT_MOSI, TFT_MISO);
    Arduino_ILI9341 display = Arduino_ILI9341(&bus, TFT_RESET);

    display.begin();
    display.fillScreen(GREEN);
    

    UserInput* userInput = UserInput::getInstance();

    while (true) {
      delay(100);
      if (userInput->isPressedLeftButton()) {
        display.fillScreen(BLACK);
      }
      if (userInput->isPressedRightButton()) {
        display.fillScreen(WHITE);
      }
      if (userInput->isPressedJoysticUp()) {
        display.fillScreen(GREEN);
      }
      if (userInput->isPressedJoysticDown()) {
        display.fillScreen(BLUE);
      }
      if (userInput->isPressedJoysticLeft()) {
        display.fillScreen(ORANGE);
      }
      if (userInput->isPressedJoysticRight()) {
        display.fillScreen(BLACK);
      }
      if (userInput->isPressedJoysticButton()) {
        display.fillScreen(WHITE);
      }
    }
}

void loop()
{
}
