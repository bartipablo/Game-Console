#include "SnakeDisplay.h"

namespace snakedisplay {
    

void drawSnake(snake::Snake& snake) {
    using snake::Snake;
    Arduino_ILI9341* display = DigitalLCD::getInstance();

    for (int i = 1; i < snake.getBodyPositions().size(); i++) {
        display->fillRect(
            snake.getBodyPositions()[i].x()*Snake::SIZE, 
            snake.getBodyPositions()[i].y()*Snake::SIZE, 
            Snake::SIZE, 
            Snake::SIZE, 
            Color::GREEN_
        );
    }
}


void updateSnake(snake::Snake& snake) {
    using snake::Snake;
    Arduino_ILI9341* display = DigitalLCD::getInstance();

    display->fillRect(
        snake.getPreviousTailPosition().x()*Snake::SIZE, 
        snake.getPreviousTailPosition().y()*Snake::SIZE, 
        Snake::SIZE, 
        Snake::SIZE, 
        Color::BLACK_
    );

    display->fillRect(
        snake.getHeadPosition().x()*Snake::SIZE, 
        snake.getHeadPosition().y()*Snake::SIZE, 
        Snake::SIZE, 
        Snake::SIZE, 
        Color::GREEN_
    );
}


void drawFruit(snake::Fruit& fruit) {
    using snake::Fruit;
    Arduino_ILI9341* display = DigitalLCD::getInstance();

    display->fillRect(
        fruit.getPosition().x()*Fruit::SIZE, 
        fruit.getPosition().y()*Fruit::SIZE, 
        Fruit::SIZE, 
        Fruit::SIZE, 
        Color::RED_
    );
}


void drawRightBoundary() {
    using snake::Area;
    using snake::Snake;

    Arduino_ILI9341* display = DigitalLCD::getInstance();
    
    display->fillRect(
        Area::WIDTH*Snake::SIZE, 
        0, 
        1,
        DigitalLCD::Y_BOUNDARY,
        Color::WHITE_
    );
}


void drawScoreTitle() {
    Arduino_ILI9341* display = DigitalLCD::getInstance();

    display->setTextSize(2);
    display->setCursor(242, 40);
    display->setTextColor(Color::WHITE_); 
    display->print("SCORE:");
    
}


void drawScore(snake::Score& score) {
    Arduino_ILI9341* display = DigitalLCD::getInstance();

    display->fillRect(250, 60, 70, 30, Color::BLACK_);

    int scoreQuantity { score.getScore() };

    char buffer[5];  
    sprintf(buffer, "%04d", scoreQuantity);

    display->setTextSize(2);
    display->setCursor(250, 60);
    display->setTextColor(Color::WHITE_);
    display->print(buffer);
}


void drawGameOver(snake::Score& score) {
    Arduino_ILI9341* display = DigitalLCD::getInstance();

    int scoreQuantity  { score.getScore() };

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