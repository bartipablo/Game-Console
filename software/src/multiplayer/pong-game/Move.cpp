#include "Move.h"

namespace pong {

void Move::write(OutputMemoryStream &stream) {
    stream.write(&y, sizeof(y));
}

void Move::read(InputMemoryStream &stream) {
    stream.read(&y, sizeof(y));
}

}