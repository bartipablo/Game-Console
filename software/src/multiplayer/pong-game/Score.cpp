#include "Score.h"

namespace pong {

Score::Score() : score(0) {}

void Score::write(OutputMemoryStream &stream) {
    stream.write(&score, sizeof(score));
}


void Score::read(InputMemoryStream &stream) {
    stream.read(&score, sizeof(score));
}

}