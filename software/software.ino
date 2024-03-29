#include <Arduino_GFX_Library.h>

#include "./src/UserInput.h"
#include "Vector2D.h"
#include "Block.h"
#include "PlayingField.h"
#include "TetrisDisplay.h"
#include "PlayingField.h"
#include "Tetromino.h"
#include "TetrominoStraight.h"
#include "TetrominoT.h"
#include <vector>
#include <memory>
#include "TetrominoSquare.h"
#include "TetrominoL2.h"
#include "TetrominoL1.h"
#include "TetrominoSkew1.h"
#include "TetrominoSkew2.h"
#include "TetrominoFactory.h"





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

   PlayingField playingField = PlayingField();


void setup()
{

    UserInput::init(LEFT_BUTTON, RIGHT_BUTTON, JOYSTIC_X, JOYSTIC_Y, JOYSTIC_BUTTON);


    Serial.begin(115200);

    Arduino_ESP32SPI bus = Arduino_ESP32SPI(TFT_DC, TFT_CS, TFT_SCK, TFT_MOSI, TFT_MISO);
    Arduino_ILI9341 display = Arduino_ILI9341(&bus, TFT_RESET);

    int color = display.color565(255, 0, 0);
    display.begin();
    display.fillScreen(GREEN);

    Vector2D initalPosition = Vector2D(4, 4);
    TetrominoFactory factory = TetrominoFactory(playingField);
    Tetromino* t = factory.getRandomTetromino();

    TetrominoL2 straightTetromino = TetrominoL2(initalPosition, playingField, 2);
    TetrisDisplay tetrisDisplay = TetrisDisplay(display);

    UserInput* userInput = UserInput::getInstance();

    while (true) {
        //init plansza xd
        tetrisDisplay.drawPlayinFieldWithPositions();
        tetrisDisplay.drawBlocks(t->getBlocks());

      delay(200);
      if (userInput->isPressedLeftButton()) {
          t->rotateClockwise();
      }
      if (userInput->isPressedRightButton()) {
        
      }
      if (userInput->isPressedJoysticUp()) {
            t->move(0, -1);
      }
      if (userInput->isPressedJoysticDown()) {
            t->move(0, 1);
      }
      if (userInput->isPressedJoysticLeft()) {
            t->move(-1, 0);
      }
      if (userInput->isPressedJoysticRight()) {
          t->move(1, 0);
      }
      if (userInput->isPressedJoysticButton()) {
       
      }
    }
    delete t;
}

void loop()
{
}
