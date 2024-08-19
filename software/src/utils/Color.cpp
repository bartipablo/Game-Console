#include "Color.h"


const int Color::YELLOW_ = 65472;

const int Color::BLUE_ = 2079;

const int Color::GREEN_ = 3905;

const int Color::RED_ = 63488;

const int Color::GRAY_=21162;

const int Color::BLACK_=0;

const int Color::WHITE_=65535;


Color::Color() {
    colorRGB565 = 0;
}


Color::Color(int colorRGB565) {
    this->colorRGB565 = colorRGB565;
}


int Color::getColorRGB565() {
    return colorRGB565;
}