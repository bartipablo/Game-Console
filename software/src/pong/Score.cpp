#include "PongScore.h"

namespace pong {

Score::Score() : score(0) {}

void Score::write(streams::OutputMemoryStream &stream) {
    stream.write(&score, sizeof(score));
}


void Score::read(streams::InputMemoryStream &stream) {
    stream.read(&score, sizeof(score));
}

}