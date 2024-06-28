#include "ConsoleClientDisplay.h"

namespace pong {

ConsoleClientDisplay::ConsoleClientDisplay(Score* clientOneScore, Score* clientTwoScore, Ball* ball, Paddle* clientOnePaddle, Paddle* clientTwoPaddle) {
    this->clientOneScore = clientOneScore;
    this->clientTwoScore = clientTwoScore;
    this->ball = ball;
    this->clientOnePaddle = clientOnePaddle;
    this->clientTwoPaddle = clientTwoPaddle;

    ballXPrevPosition = ball->getX();
    ballYPrevPosition = ball->getY();

    clientOnePaddleXPrevPosition = clientOnePaddle->getX();
    clientOnePaddleYPrevPosition = clientOnePaddle->getY();

    clientTwoPaddleXPrevPosition = clientTwoPaddle->getX();
    clientTwoPaddleYPrevPosition = clientTwoPaddle->getX();
}


void ConsoleClientDisplay::drawSummary(std::string message, Color color) {
    uint8_t originalRotation = display->getRotation();
    display->setRotation(3); 

    uint16_t screenWidth = 320;
    uint16_t screenHeight = 240;

    display->setTextSize(4);
    uint16_t textWidth = message.length() * 6 * 4;
    uint16_t textHeight = 8 * 4;
    int16_t startX = (screenWidth - textWidth) / 2;
    int16_t startY = (screenHeight - textHeight) / 2;

    display->setCursor(startX, startY);
    display->setTextColor(color.getColorRGB565()); 
    display->print(message.c_str());


    display->setRotation(originalRotation);     
}


void ConsoleClientDisplay::drawPaddles() {
    uint8_t originalRotation = display->getRotation();
    display->setRotation(3);

    display->fillRect(clientOnePaddleXPrevPosition,
                      clientOnePaddleYPrevPosition, 
                      Paddle::WIDTH,
                      Paddle::HEIGHT,
                      Color::BLACK_);
    
    display->fillRect(clientTwoPaddleXPrevPosition,
                      clientTwoPaddleYPrevPosition, 
                      Paddle::WIDTH,
                      Paddle::HEIGHT,
                      Color::BLACK_);

    display->fillRect(clientOnePaddle->getX(),
                      clientOnePaddle->getY(), 
                      Paddle::WIDTH,
                      Paddle::HEIGHT,
                      Color::WHITE_);

    display->fillRect(clientTwoPaddle->getX(),
                      clientTwoPaddle->getY(), 
                      Paddle::WIDTH,
                      Paddle::HEIGHT,
                      Color::WHITE_);

    clientOnePaddleXPrevPosition = clientOnePaddle->getX();
    clientOnePaddleYPrevPosition = clientOnePaddle->getY();

    clientTwoPaddleXPrevPosition = clientTwoPaddle->getX();
    clientTwoPaddleYPrevPosition = clientTwoPaddle->getY();

    display->setRotation(originalRotation);    
}


void ConsoleClientDisplay::drawBall() {
    uint8_t originalRotation = display->getRotation();
    display->setRotation(3);

    display->fillRect(ballXPrevPosition,
                      ballYPrevPosition, 
                      Ball::LENGTH,
                      Ball::LENGTH,
                      Color::BLACK_);
    
    display->fillRect(ball->getX(),
                      ball->getY(), 
                      Ball::LENGTH,
                      Ball::LENGTH,
                      Color::WHITE_);

    ballXPrevPosition = ball->getX();
    ballYPrevPosition = ball->getY();
                      
    display->setRotation(originalRotation); 
}


void ConsoleClientDisplay::drawScoreBoard() {
    uint8_t originalRotation = display->getRotation();
    display->setRotation(3);

    std::ostringstream oss;
    oss << clientOneScore->getScore() << "  :  " << clientTwoScore->getScore();
    display->fillRect(120, 0, 120, 19, Color::BLACK_);
    display->setCursor(120, 0);
    display->setTextColor(Color::WHITE_);
    display->setTextSize(2);
    display->println(oss.str().c_str());
                      
    display->setRotation(originalRotation); 
}


void ConsoleClientDisplay::drawLine() {
    uint8_t originalRotation = display->getRotation();
    display->setRotation(3); 

    display->fillRect(0, 20, 320, 1, Color::WHITE_);

    display->setRotation(originalRotation);
}

}