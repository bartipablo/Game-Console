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
            clearAtPosition(Vector2D(x, y));
        }
    }  
}

void TetrisDisplay::clearAtPosition(Vector2D position) {
    int x = position.x();
    int y = position.y();
    display->drawRect(PLAYING_FIELD_BEGIN_X + y * 12, PLAYING_FIELD_BEGIN_Y - x * 12, SQUARE_SIZE, SQUARE_SIZE, BLACK);
    display->fillRect(PLAYING_FIELD_BEGIN_X + y * 12 + 1, PLAYING_FIELD_BEGIN_Y - x * 12 + 1, 10, 10, WHITE);

}


void TetrisDisplay::clearAtPositions(std::vector<Vector2D> positions) {
    for (const Vector2D& pos : positions) {
        clearAtPosition(pos);
    }
}


void TetrisDisplay::displayPlayingField(const PlayingField& playingField) {
    std::vector<Vector2D> positions = playingField.getAllKeys();

    for (const Vector2D& pos : positions) {
        if (playingField.isEmpty(pos)) {
            clearAtPosition(pos);
        } else {
            Block block = playingField.getFromPosition(pos);
            drawBlock(block);
        }
    }
}


void TetrisDisplay::test() {
    display->fillScreen(RED);
}

void TetrisDisplay::test1() {
    display->fillScreen(GREEN);
}