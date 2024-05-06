#ifndef PongConsoleClientDisplay_H
#define PongConsoleClientDisplay_H

#include <string>
#include <sstream>

#include "../../utils/DigitalLCD.h"
#include "../../common/Color.h"

#include "../pong-game/Ball.h"
#include "../pong-game/Paddle.h"
#include "../pong-game/Score.h"

namespace pong {

class ConsoleClientDisplay {
public:
    ConsoleClientDisplay(Score* clientOneScore, Score* clientTwoScore, Ball* ball, Paddle* clientOnePaddle, Paddle* clientTwoPaddle);

    void drawInfo(std::string message, std::string title);

    void drawSummary(std::string message, Color color);

    void clearScreen();

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