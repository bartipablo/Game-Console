#include "ColorBox.h"

namespace paint {

ColorBox::ColorBox() : selectedColorIndex{0}, actualColorIndex{0} {
    colorsQuantity = colors.size();
}


Color ColorBox::getSelectedColor() {
    if (selectedColorIndex >= colorsQuantity || selectedColorIndex < 0) {
        selectedColorIndex = 0;
    }
    return colors[selectedColorIndex];
}


Color ColorBox::getActualColor() {
    if (actualColorIndex >= colorsQuantity || actualColorIndex < 0) {
        actualColorIndex = 0;
    }
    return colors[actualColorIndex];
}


void ColorBox::nextColor() {
    actualColorIndex++;
    if (actualColorIndex >= colorsQuantity) {
        actualColorIndex = 0;
    }
}


void ColorBox::previousColor() {
    actualColorIndex--;
    if (actualColorIndex < 0) {
        actualColorIndex = colorsQuantity - 1;
    }
}


void ColorBox::selectColor() {
    selectedColorIndex = actualColorIndex;
}

}