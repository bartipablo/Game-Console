#include "SnakeDisplay.h"

#include "../common/Color.h"

namespace snake {

void SnakeDisplay::drawSnake(Snake* snake) {
    for (int i = 1; i < snake->getLength(); i++) {
        display->fillRect(
            snake->getBody()[i].getPosition().x(), 
            snake->getBody()[i].getPosition().y(), 
            Snake::SIZE, 
            Snake::SIZE, 
            Color::GREEN_
        );
    }
}

void SnakeDisplay::updateSnake(Snake* snake) {
    display->fillRect(
        snake->gePreviousTail()->getPosition().x(), 
        snake->gePreviousTail()->getPosition().y(), 
        Snake::SIZE, 
        Snake::SIZE, 
        Color::BLACK_
    );

    display->fillRect(
        snake->getHead()->getPosition().x(), 
        snake->getHead()->getPosition().y(), 
        Snake::SIZE, 
        Snake::SIZE, 
        Color::GREEN_
    );
    display->fillRect(
        snake->getTail()->getPosition().x(), 
        snake->getTail()->getPosition().y(), 
        Snake::SIZE,
        Snake::SIZE,
        Color::GREEN_
    );
}

void SnakeDisplay::drawFruit(Fruit* fruit) {
    display->fillRect(
        fruit->getPosition().x(), 
        fruit->getPosition().y(), 
        Fruit::SIZE, 
        Fruit::SIZE, 
        Color::RED_
    );
}


}