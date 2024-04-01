#ifndef TetrisDisplay_H
#define TetrisDisplay_H

#define LCD_WIDTH 320
#define LCD_HEIGHT 240
#define SQUARE_SIZE 12
#define X_PLAYING_FIELD 88
#define Y_PLAYING_FIELD 0

#include "Block.h"
#include "../DigitalLCD.h"
#include "../Color.h"
#include "PlayingField.h"

#include <vector>

/**
 * @brief Class representing a display for Tetris game.
 * 
 * The TetrisDisplay class provides methods to interact with a display 
 * for Tetris game, including drawing blocks, displaying score and level, 
 * and handling game over screen.
 */
class TetrisDisplay {
public:    
    TetrisDisplay();

    /**
     * @brief Draws a block on PlayingField on the display.
     * 
     * @param block The block to be drawn.
     */
    void drawBlock(Block block);

    void drawBlocks(const std::vector<Block>& blocks);

    /**
     * @brief Clears the block at a specified position on PlayingField on the display.
     * 
     * @param position The position of the block to be cleared.
     */
    void clearAtPosition(Vector2D position);

    void clearAtPositions(std::vector<Vector2D> position);

    /**
     * @brief Draws the playing field on the display.
     * 
     * @param playingField The playing field to be displayed.
     */
    void drawPlayingField(const PlayingField& playingField);

    /**
     * @brief Draws the empty playing field with positions on the display.
     */
    void drawEmptyPlayingField();

    /**
     * @brief Displays the SCORE, LEVEL, NEXT titles.
     */
    void drawFieldsDescription();

    /**
     * @brief Clears the score displayed on the display.
     */
    void clearScore();

    /**
     * @brief Clears the level displayed on the display.
     */
    void clearLevel();

    /**
     * @brief Clears the next displayed on the display.
     */
    void clearNext();

    /**
     * @brief Displays the score value on the display.
     * 
     * @param score The score to be displayed.
     */
    void drawScore(int score);

    /**
     * @brief Displays the level value on the display.
     * 
     * @param score The score to be displayed.
     */
    void drawLevel(int level);

    /**
     * @brief Displays the next block on the display.
     * 
     * @param score The score to be displayed.
     */
    void drawNext(std::vector<Block> blocks);

    /**
     * @brief Displays the game over screen on the display.
     * 
     * @param score The final score of the game.
     * @param level The final level achieved in the game.
     */
    void displayGameOver(int score, int level);

private:
    Arduino_ILI9341* display;
};


#endif
