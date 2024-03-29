#ifndef Block_H
#define Block_H

#include "Arduino.h"
#include "Vector2D.h"

class Block
{
public:
  Block(int color, Vector2D position) : color(color), position(position) {
  }

  int getColor();

  Vector2D getPosition();

private:
  int color;

  Vector2D position;

};

#endif