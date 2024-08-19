#include "Move.h"

namespace pong {

void Move::write(streams::OutputMemoryStream &stream) {
    stream.write(&y, sizeof(y));
}

void Move::read(streams::InputMemoryStream &stream) {
    stream.read(&y, sizeof(y));
}

}