#include "TetrominoFactory.h"

TetrominoFactory::TetrominoFactory(PlayingField& playingField)
    : playingField(playingField) {
        randomSeed(analogRead(18));
    }


Tetromino* TetrominoFactory::getRandomTetromino() {
    int color = getRandomColor();
    int randomNumber = getRandomNumber(7);
    switch (randomNumber) {
        case 1: {
            return new TetrominoL1(Vector2D(4, 0), playingField, color);
        }
        case 2: {
            return new TetrominoL2(Vector2D(5, 0), playingField, color);
        }
        case 3: {
            return new TetrominoT(Vector2D(4, 0), playingField, color);
        }
        case 4: {
            return new TetrominoSkew1(Vector2D(4, 0), playingField, color);
        }
        case 5: {
            return new TetrominoSkew2(Vector2D(5, 0), playingField, color);
        }
        case 6: {
            return new TetrominoStraight(Vector2D(4, 0), playingField, color);
        }
        default: {
            return new TetrominoSquare(Vector2D(4, 0), playingField, color);
        }
    }
}


int TetrominoFactory::getRandomColor() {
    int randomNumber = getRandomNumber(4);
    switch(randomNumber) {
        case 1:
            return Color::BLUE_;
        case 2:
            return Color::GREEN_;
        case 3:
            return Color::RED_;
        default:
            return Color::YELLOW_;
    }
}



int TetrominoFactory::getRandomNumber(int range) {
    return random(1, range);
}