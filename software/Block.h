#ifndef Block_H
#define Block_H

#include "Arduino.h"
#include "Vector2D.h"

class Block
{
public:
  Block() : color(0), position(Vector2D()) {}

  Block(int color, Vector2D position) : color(color), position(position) {
  }

  int getColor();

  Vector2D getPosition();

  void updatePosition(const Vector2D newPosition);

private:
  int color;

  Vector2D position;
};

#endif