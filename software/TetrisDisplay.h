#ifndef TetrisDisplay_H
#define TetrisDisplay_H

#define LCD_WIDTH 320
#define LCD_HEIGHT 240
#define SQUARE_SIZE 12
#define PLAYING_FIELD_BEGIN_X 0
#define PLAYING_FIELD_BEGIN_Y 220

#include <Arduino_GFX_Library.h>
#include "Arduino.h"
#include "Block.h"
#include <vector>
#include "./src/DigitalLCD.h"

class TetrisDisplay {
public:    
    TetrisDisplay();

    void drawBlock(Block block);

    void drawBlocks(const std::vector<Block>& blocks);

    void drawPlayinFieldWithPositions();

private:
    Arduino_ILI9341* display;
};


#endif
