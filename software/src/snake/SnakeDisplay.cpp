#include "SnakeDisplay.h"

#include "../common/Color.h"

namespace snake {

void SnakeDisplay::drawSnake(Snake* snake) {

    for (int i = 1; i < snake->getBodyPositions().size(); i++) {
        display->fillRect(
            snake->getBodyPositions()[i].x()*Snake::SIZE, 
            snake->getBodyPositions()[i].y()*Snake::SIZE, 
            Snake::SIZE, 
            Snake::SIZE, 
            Color::GREEN_
        );
    }
}


void SnakeDisplay::updateSnake(Snake* snake) {
    display->fillRect(
        snake->getPreviousTailPosition().x()*Snake::SIZE, 
        snake->getPreviousTailPosition().y()*Snake::SIZE, 
        Snake::SIZE, 
        Snake::SIZE, 
        Color::BLACK_
    );

    display->fillRect(
        snake->getHeadPosition().x()*Snake::SIZE, 
        snake->getHeadPosition().y()*Snake::SIZE, 
        Snake::SIZE, 
        Snake::SIZE, 
        Color::GREEN_
    );
    display->fillRect(
        snake->getTailPosition().x()*Snake::SIZE, 
        snake->getTailPosition().y()*Snake::SIZE, 
        Snake::SIZE,
        Snake::SIZE,
        Color::GREEN_
    );
}


void SnakeDisplay::drawFruit(Fruit* fruit) {
    display->fillRect(
        fruit->getPosition().x()*Fruit::SIZE, 
        fruit->getPosition().y()*Fruit::SIZE, 
        Fruit::SIZE, 
        Fruit::SIZE, 
        Color::RED_
    );
}


void SnakeDisplay::drawRightBoundary() {
    
    display->fillRect(
        Area::WIDTH*Snake::SIZE, 
        0, 
        1,
        DigitalLCD::Y_BOUNDARY,
        Color::WHITE_
    );
}

void SnakeDisplay::drawScoreTitle() {
    display->setTextSize(2);
    display->setCursor(242, 40);
    display->setTextColor(Color::WHITE_); 
    display->print("SCORE:");
    
}


void SnakeDisplay::drawScore(Score* score) {
    display->fillRect(250, 60, 70, 30, Color::BLACK_);

    int scoreQuantity = score->getScore();

    char buffer[5];  
    sprintf(buffer, "%04d", scoreQuantity);

    display->setTextSize(2);
    display->setCursor(250, 60);
    display->setTextColor(Color::WHITE_);
    display->print(buffer);
}



void SnakeDisplay::drawGameOver(Score* score) {
    int scoreQuantity = score->getScore();

    char buffer[5];
    sprintf(buffer, "%04d", scoreQuantity);

    display->setTextSize(4);    
    display->setCursor(60, 30);
    display->println("GAME OVER");

    display->setTextSize(3);    
    display->setCursor(50, 90);
    display->print("SCORE: ");
    display->println(buffer);
}


}