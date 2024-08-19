#ifndef SnakeDisplay_H
#define SnakeDisplay_H

#include "DigitalLCD.h"
#include "Snake.h"
#include "Fruit.h"
#include "Area.h"
#include "Color.h"
#include "SnakeScore.h"

/**
 * Methods for display of the snake game.
 */
namespace snakedisplay {

/**
 * Draw a whole snake
 */
void drawSnake(snake::Snake& snake);

/**
 * Draw a snake's head and remove the previous tail
 */
void updateSnake(snake::Snake& snake);

void drawFruit(snake::Fruit& fruit);

void drawRightBoundary();

void drawScoreTitle();

void drawScore(snake::Score& score);

void drawGameOver(snake::Score& score);

}

#endif