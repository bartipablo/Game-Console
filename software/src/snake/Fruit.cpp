#include "Fruit.h"

#include <vector>
#include <algorithm>  
#include <random>
#include <chrono>

namespace snake {

Vector2D Fruit::getPosition() {
    return position;
}

void Fruit::generateAtRandomPosition(Snake* snake, Area* area) {
    std::vector<int> x;
    std::vector<int> y;

    for (int i = 0; i < Area::WIDTH; i++) {
        x.push_back(i);
    }

    for (int i = 0; i < Area::HEIGHT; i++) {
        y.push_back(i);
    }

    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    unsigned seed2 = seed1 + 1;

    std::default_random_engine engine1(seed1);
    std::default_random_engine engine2(seed2);

    std::shuffle(x.begin(), x.end(), engine1);
    std::shuffle(y.begin(), y.end(), engine2);

    for (int i = 0; i < Area::WIDTH; i++) {
        for (int j = 0; j < Area::HEIGHT; j++) {
            Vector2D newPosition(x[i], y[j]);

            if (!snake->isAtPosition(newPosition)) {
                position = newPosition;
                return;
            }
        }
    }

}


}