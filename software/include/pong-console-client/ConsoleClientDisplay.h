#ifndef PongConsoleClientDisplay_H
#define PongConsoleClientDisplay_H

#include <string>
#include <sstream>

#include "DigitalLCD.h"
#include "Color.h"

#include "Ball.h"
#include "Paddle.h"
#include "PongScore.h"

namespace pong {

class ConsoleClientDisplay {
public:
    ConsoleClientDisplay(Score* clientOneScore, Score* clientTwoScore, Ball* ball, Paddle* clientOnePaddle, Paddle* clientTwoPaddle);

    void drawSummary(std::string message, Color color);

    void drawPaddles();

    void drawBall();
    
    void drawScoreBoard();

    void drawLine();

private:
    Score* clientOneScore;

    Score* clientTwoScore;

    // ball ------------------------------
    int ballXPrevPosition;

    int ballYPrevPosition;

    Ball* ball;
    // ball ------------------------------

    // client one paddle -----------------
    int clientOnePaddleXPrevPosition;

    int clientOnePaddleYPrevPosition;

    Paddle* clientOnePaddle;
    // client one paddle -----------------

    // client two paddle -----------------
    int clientTwoPaddleXPrevPosition;

    int clientTwoPaddleYPrevPosition;

    Paddle* clientTwoPaddle;
    // client two paddle -----------------

    Arduino_ILI9341* display = DigitalLCD::getInstance();    
};


}

#endif