#ifndef ColorBox_H
#define ColorBox_H

#include <vector>

#include "../Color.h"

class ColorBox {

public:
    ColorBox();

    Color getSelectedColor();

    Color getActualColor();

    void nextColor();

    void previousColor();

    void selectColor();

private:
    int colorsQuantity;

    int selectedColorIndex;

    int actualColorIndex;

    std::vector<Color> colors = {
        Color(Color::BLACK_), 
        Color(Color::YELLOW_), 
        Color(Color::BLUE_), 
        Color(Color::GREEN_), 
        Color(Color::RED_),
        Color(Color::GRAY_), 
        Color(Color::WHITE_)
    };
};


#endif