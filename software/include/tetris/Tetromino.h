#ifndef Tetromino_H
#define Tetromino_H

#include "Block.h"
#include "Vector2D.h"
#include "Direction.h"
#include "TetrisProperties.h"
#include "PlayingField.h"
#include <vector>

namespace tetris {

/**
 * @brief Class representing a Tetromino object in the Tetris game.
 * 
 * Tetromino class defines the behavior and properties of a Tetromino, which
 * is a geometric shape composed of four square blocks used in the game of Tetris.
 */
class Tetromino {
public:
    /**
     * @brief Constructor for the Tetromino class.
     * 
     * Initializes a Tetromino object with the specified rotation matrices and blocks.
     * 
     * @param xRotateInit Rotation matrix for clockwise rotation.
     * @param yRotateInit Rotation matrix for clockwise rotation.
     * @param xAntiRotateInit Rotation matrix for anti-clockwise rotation.
     * @param yAntiRotateInit Rotation matrix for anti-clockwise rotation.
     * @param blocksInit Array of blocks composing the Tetromino.
     */
    Tetromino(int xRotateInit[4][4], int yRotateInit[4][4], int xAntiRotateInit[4][4], int yAntiRotateInit[4][4], Block blocksInit[4]);

    /**
     * @brief Method to rotate the Tetromino clockwise.
     * 
     * Rotates the Tetromino 90 degrees clockwise within the game's boundary.
     * 
     * @param playingField The playing field where the Tetromino is placed.
     */
    void rotateClockwise(const PlayingField& playingField);

    /**
     * @brief Method to rotate the Tetromino anti-clockwise.
     * 
     * Rotates the Tetromino 90 degrees anti-clockwise within the game's boundary.
     * 
     * @param playingField The playing field where the Tetromino is placed.
     */
    void rotateAntiClockwise(const PlayingField& playingField);

    /**
     * @brief Method to retrieve the blocks composing the Tetromino.
     * 
     * Retrieves the blocks that make up the Tetromino.
     * 
     * @return Vector of Block objects.
     */
    std::vector<Block> getBlocks();

    /**
     * @brief Method to retrieve the positions of the Tetromino's blocks.
     * 
     * Retrieves the positions of the blocks that make up the Tetromino.
     * 
     * @return Vector of Vector2D objects representing block positions.
     */

    std::vector<Vector2D> getPositions();

    /**
     * @brief Method to move the Tetromino in the specified direction.
     * 
     * Moves the Tetromino horizontally and/or vertically within the game's boundary.
     * 
     * @param x The horizontal movement (left or right).
     * @param y The vertical movement (up or down).
     * @param playingField The playing field where the Tetromino is placed.
     */
    void move(int x, int y, const PlayingField& playingField);


private:
    int xRotate[4][4];
    
    int yRotate[4][4];

    int xAntiRotate[4][4];
    
    int yAntiRotate[4][4];

    static constexpr int BLOCKS_QUANTITY = 4;

    Block blocks[BLOCKS_QUANTITY];

    Direction direction;

    /**
     * @brief Method to rotate the Tetromino for specific shapes.
     * 
     * Rotates the Tetromino using custom rotation matrices based on its current shape.
     * 
     * @param xRotate Rotation matrix for the clockwise rotation.
     * @param yRotate Rotation matrix for the clockwise rotation.
     * @param playingField The playing field where the Tetromino is placed.
     * @param newDirection Function pointer to calculate the new direction after rotation.
     */
    void rotateForSpecyficTetrominos(int xRotate[4][4], int yRotate[4][4], const PlayingField& playingField, Direction (*newDirection)(Direction));
};

}

#endif
