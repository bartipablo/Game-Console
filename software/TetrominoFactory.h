#ifndef TetrominoFactory_H
#define TetrominoFactory_H

#include "Tetromino.h"
#include "Color.h"
#include "TetrominoL1.h"
#include "TetrominoL2.h"
#include "TetrominoSkew1.h"
#include "TetrominoSkew2.h"
#include "TetrominoSquare.h"
#include "TetrominoStraight.h"
#include "TetrominoT.h"
#include "Vector2D.h"
#include "PlayingField.h"
#include "Arduino.h"

#include <random>


class TetrominoFactory {
public:
    TetrominoFactory(PlayingField& playingField);

    Tetromino* getRandomTetromino();
private:
    PlayingField playingField;

    int getRandomColor();

    int getRandomNumber(int range);
};

#endif
