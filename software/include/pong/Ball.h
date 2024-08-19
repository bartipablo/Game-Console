#ifndef BALL_H
#define BALL_H

#include "Serializable.h"
#include "Paddle.h"
#include "Table.h"

#include <cmath>
#include <random>
#include <cstdint>

namespace pong {

/**
 * The ball class represents the ball in the Pong game.
*/
class Ball : public streams::Serializable {

public:
    Ball(int x, int y);

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

/**
 * Reset the ball to the initial position and set the speed to zero.
 * Used when a player scores a point.
*/
    void reset();

/**
 * Update the ball position.
*/
    void update();

/**
 * Bounces the ball off the paddle.
 * @param paddle The paddle that the ball will bounce off.
*/
    void bouncesOffPaddle(Paddle& paddle);

/**
 * Check if the ball is colliding with the paddle.
 * @param paddle The paddle to check collision with.
 * @return True if the ball is colliding with the paddle, false otherwise.
 */
    bool isCollisionWithPaddle(Paddle& paddle);

/**
 * Check if the ball is colliding with the wall.
 * @return True if the ball is colliding with the wall, false otherwise.
 */
    bool isCollisionWithWall();

/**
 * Check if the ball is behind the player paddle.
 * @param paddle The paddle to check if the ball is behind.
 * @return True if the ball is behind the paddle, false otherwise.
 */
    bool isBehindPaddle(Paddle& paddle);

/**
 * Bounces the ball off the wall.
 * Used when the ball hits the top or bottom wall.
*/
    void bouncesOffWall();

/**
 * Launch the ball.
 * Used when the round starts.
*/
    void launch();

    void write(streams::OutputMemoryStream &stream) override;

    void read(streams::InputMemoryStream &stream) override;

    static const int LENGTH = 6;

private:
    float angle;

    int16_t x;
    const int16_t initX;
    
    int16_t y;
    const int16_t initY;

    int dx;

    int dy;

    int speed;
};

}

#endif