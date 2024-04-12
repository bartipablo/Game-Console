#ifndef TetrominoFactory_H
#define TetrominoFactory_H

#include "Tetromino.h"
#include "../common/Color.h"
#include "../common/Vector2D.h"
#include "PlayingField.h"
#include "Arduino.h"

#include <random>


/**
 * @brief Class responsible for creating Tetromino objects.
 * 
 * The TetrominoFactory class is a factory that generates random Tetromino objects
 * with various shapes and colors, which can be used in the Tetris game.
 */
class TetrominoFactory {
public:
    TetrominoFactory();

    /**
     * @brief Method to generate a random Tetromino.
     * 
     * Generates a random Tetromino shape along with a random color.
     * 
     * @return Pointer to the Tetromino object.
     */

    Tetromino* getRandomTetromino();

private:
    /**
     * @brief Method to generate a random color.
     * 
     * Generates a random color that will be assigned to the Tetromino.
     * 
     * @return Random color.
     */
    int getRandomColor();

    /**
     * @brief Method to generate a random number within a given range.
     * 
     * Generates a random number within the specified range.
     * 
     * @param range The range for random number generation.
     * @return Random number within the [0, range].
     */
    int getRandomNumber(int range);


    /**
     * @brief Method to create an L1 shape (L-shaped tetromino) Tetromino.
     * 
     * ⬛
     * ⬛⬛⬛
     * @param initialPosition The initial position of the Tetromino.
     * @param color The color of the Tetromino.
     * @return Pointer to the Tetromino object of type L1.
     */
    Tetromino* createL1Tetromino(Vector2D initialPosition, int color);

    /**
     * @brief Method to create an L2 shape (L-shaped tetromino) Tetromino.
     * 
     *      ⬛
     * ⬛⬛⬛
     * @param initialPosition The initial position of the Tetromino.
     * @param color The color of the Tetromino.
     * @return Pointer to the Tetromino object of type L2.
     */
    Tetromino* createL2Tetromino(Vector2D initialPosition, int color);

    /**
     * @brief Method to create an Skew1 shape (S-shaped tetromino) Tetromino.
     * 
     *    ⬛⬛
     * ⬛⬛
     * @param initialPosition The initial position of the Tetromino.
     * @param color The color of the Tetromino.
     * @return Pointer to the Tetromino object of type Skew1.
     */
    Tetromino* createSkew1Tetromino(Vector2D initialPosition, int color);

    /**
     * @brief Method to create an Skew2 shape (S-shaped tetromino) Tetromino.
     * 
     * ⬛⬛
     *    ⬛⬛
     * @param initialPosition The initial position of the Tetromino.
     * @param color The color of the Tetromino.
     * @return Pointer to the Tetromino object of type Skew2.
     */
    Tetromino* createSkew2Tetromino(Vector2D initialPosition, int color);

    /**
     * @brief Method to create an Square shape (Square-shaped tetromino) Tetromino.
     * 
     * ⬛⬛
     * ⬛⬛
     * @param initialPosition The initial position of the Tetromino.
     * @param color The color of the Tetromino.
     * @return Pointer to the Tetromino object of type Square.
     */
    Tetromino* createSquareTetromino(Vector2D initialPosition, int color);

    /**
     * @brief Method to create an Straight shape (Straight-shaped tetromino) Tetromino.
     * 
     * ⬛⬛⬛⬛
     * @param initialPosition The initial position of the Tetromino.
     * @param color The color of the Tetromino.
     * @return Pointer to the Tetromino object of type Straight.
     */
    Tetromino* createStraightTetromino(Vector2D initialPosition, int color);

    /**
     * @brief Method to create an T shape (T-shaped tetromino) Tetromino.
     * 
     * ⬛⬛⬛
     *   ⬛
     * @param initialPosition The initial position of the Tetromino.
     * @param color The color of the Tetromino.
     * @return Pointer to the Tetromino object of type T.
     */
    Tetromino* createTTetromino(Vector2D initialPosition, int color);
};

#endif