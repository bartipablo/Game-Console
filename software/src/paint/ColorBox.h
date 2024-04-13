#ifndef ColorBox_H
#define ColorBox_H

#include <vector>

#include "../common/Color.h"

/**
 * @brief Class representing a color box.
 * The color box is a box that contains a set of colors.
 * The user can select a color from the color box.
 */
class ColorBox {

public:
    ColorBox();

/**
 * @return the selected color.
 * The selected color is the color that the user will be using to draw.
*/
    Color getSelectedColor();

/**
 * @return the actual color.
 * The actual color is the color that is currently being displayed on the screen.
*/
    Color getActualColor();

/**
 * @brief Select the next color.
*/
    void nextColor();

/**
 * @brief Select the previous color.
 */
    void previousColor();

/**
 * @brief Select the actual color.
 * set the actual color as the selected color.
 */
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