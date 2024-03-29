#ifndef Playing_Field_H
#define Playing_Field_H

#include "Arduino.h"
#include "Block.h"
#include "Vector2D.h"
#include <map>
#include "optional.hpp"

class PlayingField
{
public:
    PlayingField();        
  
private:
    std::map < Vector2D, tl::optional<Block> > fields;
};

#endif