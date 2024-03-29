#include "TetrisDisplay.h"
#include "Block.h"

TetrisDisplay::TetrisDisplay() {
    this->display = DigitalLCD::getInstance();
}

void TetrisDisplay::drawBlock(Block block) {
    int x = block.getPosition().x();
    int y = block.getPosition().y();
    int color = block.getColor();

    display->drawRect(PLAYING_FIELD_BEGIN_X + y * 12, PLAYING_FIELD_BEGIN_Y - x * 12, SQUARE_SIZE, SQUARE_SIZE, BLACK);
    display->fillRect(PLAYING_FIELD_BEGIN_X + y * 12 + 1, PLAYING_FIELD_BEGIN_Y  - x * 12 + 1, SQUARE_SIZE - 2, SQUARE_SIZE - 2, color);
}

void TetrisDisplay::drawBlocks(const std::vector<Block>& blocks) {
    for(const auto& block : blocks) {
        drawBlock(block); 
    }
}


void TetrisDisplay::drawPlayinFieldWithPositions() {
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 20; y++) {
            display->drawRect(PLAYING_FIELD_BEGIN_X  + y * 12, PLAYING_FIELD_BEGIN_Y - x * 12, 12, 12, BLACK);
            display->fillRect(PLAYING_FIELD_BEGIN_X + y * 12 + 1, PLAYING_FIELD_BEGIN_Y - x * 12 + 1, 10, 10, WHITE);
        }
    }  
}