#include "Paddle.h"

namespace pong {

Paddle::Paddle(int x, int y) :x{x}, y{y}, initX{x}, initY{y} {}

void Paddle::write(streams::OutputMemoryStream &stream) {
    stream.write(&y, sizeof(y));
    stream.write(&x, sizeof(x));
}


void Paddle::read(streams::InputMemoryStream &stream) {
    stream.read(&y, sizeof(y));
    stream.read(&x, sizeof(x)); 
}


void Paddle::move(int y) {
    this->y += y;

    if (this->y + Paddle::HEIGHT > Table::HEIGHT) {
        this->y = Table::HEIGHT - Paddle::HEIGHT;
    } 
    else if (this->y < 20) {
        this->y = 20;
    }
}


void Paddle::reset() {
    x = initX;
    y = initY;
}

}