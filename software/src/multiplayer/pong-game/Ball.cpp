#include "Ball.h"

namespace pong {

std::random_device rd;
std::mt19937 gen(rd());


Ball::Ball(int x, int y) : initX(x), initY(y) {
    speed = 3;
    angle = 0.0f;

    this->x = x;
    this->y = y;

    dx = 0;
    dy = 0;
}

void Ball::write(OutputMemoryStream &stream) {
    stream.write(&x, sizeof(x));
    stream.write(&y, sizeof(y));
}

void Ball::read(InputMemoryStream &stream) {
    stream.read(&x, sizeof(x));
    stream.read(&y, sizeof(y));
}

void Ball::launch() {
    std::uniform_int_distribution<int> dir(0, 1);
    int direction = 1 + (-2) * (dir(gen) % 2);

    std::uniform_int_distribution<int> ang(-60, 60);
    angle = ang(gen);

    dx = direction * speed * std::cos(angle * M_PI / 180.0f);
    dy = speed * std::sin(angle * M_PI / 180.0f);
}

void Ball::bouncesOffPaddle(Paddle& paddle) {
    int sign = (paddle.getX() < Table::WIDTH / 2) ? 1 : -1;

    int relative_y = (y - paddle.getY() + LENGTH);

    angle = (2.14f * relative_y - 75.0f);

    dx = sign * speed * std::cos(angle * M_PI / 180.0f);

    dy = speed * std::sin(angle * M_PI / 180.0f);
}

bool Ball::isCollisionWithPaddle(Paddle &paddle) {
    // check if ball is at a same height.
    if (y + Ball::LENGTH <= paddle.getY() || y >= paddle.getY() + Paddle::HEIGHT) {
        return false;
    }
    // check if ball is at a same width.
    bool isLeftPaddle = (paddle.getX() < Table::WIDTH / 2);
    if (isLeftPaddle) {
        return (x <= paddle.getX() + Paddle::WIDTH);
    }
    else {
        return x + Ball::LENGTH >= paddle.getX();
    }
}

bool Ball::isCollisionWithWall() {
    return y <= 20 || y + Ball::LENGTH >= Table::HEIGHT - 1;
}

bool Ball::isBehindPaddle(pong::Paddle &paddle) {
    bool isLeftPaddle = (paddle.getX() < Table::WIDTH / 2);

    if (!isLeftPaddle && (x + Ball::LENGTH - Paddle::WIDTH/2 <= paddle.getX())) {
        return false;
    }
    else if (isLeftPaddle && (x + Paddle::WIDTH/2 >= paddle.getX() + Paddle::WIDTH)) {
        return false;
    }

    return (y + Ball::LENGTH <= paddle.getY() || y >= paddle.getY());
}

void Ball::bouncesOffWall() {
    dy *= -1;
}

void Ball::update() {
    x += dx;
    y += dy;
}

void Ball::reset() {
    x = initX;
    y = initY;
    dx = 0;
    dy = 0;
}

}