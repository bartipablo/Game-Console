#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include "OutputMemoryStream.h"
#include "InputMemoryStream.h"

class Serializable {
public:
    virtual void write(OutputMemoryStream& stream) = 0;

    virtual void read(InputMemoryStream& stream) = 0;
};


#endif