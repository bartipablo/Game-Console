#include "TetrisDisplay.h"
#include "Block.h"


TetrisDisplay::TetrisDisplay() {
    this->display = DigitalLCD::getInstance();
}


void TetrisDisplay::drawBlock(Block block) {
    int x = block.getPosition().x();
    int y = block.getPosition().y();
    int color = block.getColor();

    display->drawRect(X_PLAYING_FIELD + x * 12,
                      Y_PLAYING_FIELD + y * 12,
                      SQUARE_SIZE,
                      SQUARE_SIZE,
                      BLACK);
    display->fillRect(X_PLAYING_FIELD + x * 12 + 1,
                      y * 12 + 1,
                      SQUARE_SIZE - 2,
                      SQUARE_SIZE - 2,
                      color);
}


void TetrisDisplay::drawBlocks(const std::vector<Block>& blocks) {
    for(const auto& block : blocks) {
        drawBlock(block); 
    }
}


void TetrisDisplay::drawEmptyPlayingField() {
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 20; y++) {
            clearAtPosition(Vector2D(x, y));
        }
    }  
}


void TetrisDisplay::clearAtPosition(Vector2D position) {
    Block emptyField = Block(WHITE, position);
    drawBlock(emptyField); 
}


void TetrisDisplay::clearAtPositions(std::vector<Vector2D> positions) {
    for (const Vector2D& pos : positions) {
        clearAtPosition(pos);
    }
}


void TetrisDisplay::drawPlayingField(const PlayingField& playingField) {
    std::vector<Vector2D> positions = playingField.getAllPositions();

    for (const Vector2D& pos : positions) {
        if (playingField.isEmpty(pos)) {
            clearAtPosition(pos);
        } else {
            Block block = playingField.getFromPosition(pos);
            drawBlock(block);
        }
    }
}


void TetrisDisplay::drawFieldsDescription() {
    display->fillScreen(BLACK);
    display->setTextColor(WHITE);
    display->setTextSize(2);

    display->setCursor(10, 30); 
    display->println("SCORE"); 
    display->setCursor(10, 120); 
    display->println("LEVEL"); 
    display->setCursor(240, 30);  
    display->println("NEXT");
}


void TetrisDisplay::clearScore() {
    int x = 10; 
    int y = 60; 
    int width = 70; 
    int height = 30; 

    display->fillRect(x, y, width, height, BLACK);
}


void TetrisDisplay::clearLevel() {
    int x = 10; 
    int y = 150; 
    int width = 70; 
    int height = 30; 

    display->fillRect(x, y, width, height, BLACK);
}


void TetrisDisplay::clearNext() {
    int x = 220; 
    int y = 60; 
    int width = 90; 
    int height = 50; 

    display->fillRect(x, y, width, height, WHITE);
}


void TetrisDisplay::drawScore(int score) {
    String scoreString = String(score);

    while (scoreString.length() < 6) {
        scoreString = "0" + scoreString;
    }

    display->setCursor(10, 60);  
    display->println(scoreString); 
}


void TetrisDisplay::drawLevel(int level) {
    String levelString = String(level);

    while (levelString.length() < 2) {
        levelString = "0" + levelString;
    }

    display->setCursor(30, 150);  
    display->println(levelString); 
}


void TetrisDisplay::drawNext(std::vector<Block> blocks) {
    int minX = blocks[0].getPosition().x();
    int maxX = blocks[0].getPosition().x();
    int minY = blocks[0].getPosition().y();
    int maxY = blocks[0].getPosition().y();

    for (const auto& block : blocks) {
        if (block.getPosition().x() < minX) {
            minX = block.getPosition().x();
        }
        if (block.getPosition().x() > maxX) {
            maxX = block.getPosition().x();
        }
        if (block.getPosition().y() < minY) {
            minY = block.getPosition().y();
        }
        if (block.getPosition().y() > maxY) {
            maxY = block.getPosition().y();
        }
    }

    int lengthX = maxX - minX + 1;
    int lengthY = maxY - minY + 1;

    int xPositionPx;
    switch (lengthX) {
        case 2:
            xPositionPx = 205;
            break;
        case 3:
            xPositionPx = 200;
            break;
        case 4:
            xPositionPx = 205;
            break;
        default:
            xPositionPx = 200;
    }

    int yPositionPx;
    switch (lengthY) {
        case 1:
            yPositionPx = 80;
            break;
        case 2:
            yPositionPx = 70;
            break;
        default:
            yPositionPx = 75;
            break;
    }

    for (const auto& block : blocks) {
        int x = block.getPosition().x();
        int y = block.getPosition().y();
        int color = block.getColor();
        display->drawRect(xPositionPx + x * 12, yPositionPx + y * 12, SQUARE_SIZE, SQUARE_SIZE, BLACK);
        display->fillRect(xPositionPx + x * 12 + 1, yPositionPx + y * 12 + 1, 10, 10, color);
    }

}


void TetrisDisplay::displayGameOver(int score, int level) {
    String scoreString = String(score);
    while (scoreString.length() < 6) {
        scoreString = "0" + scoreString;
    }

    String levelString = String(level);
    while (levelString.length() < 2) {
        levelString = "0" + levelString;
    }

    display->fillScreen(BLACK);
    display->setTextSize(4);    
    display->setCursor(60, 30);
    display->println("GAME OVER");

    display->setTextSize(3);    
    display->setCursor(40, 90);
    display->println("SCORE: " + scoreString);

    display->setCursor(40, 130);
    display->println("LEVEL: " + levelString);

    display->setTextSize(1);  
    display->setCursor(70, 200);
    display->println("Press any key to continue...");
}