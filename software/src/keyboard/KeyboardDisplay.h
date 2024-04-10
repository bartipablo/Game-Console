#ifndef KeyboardDisplay_H
#define KeyboardDisplay_H

#include <vector>

#include "Keyboard.h"
#include "../DigitalLCD.h"
#include "../Color.h"

/**
 * @brief Class representing single key.
 * 
 */
class KeyboardDisplay {

public:
    /**
     * @brief Construct a new KeyboardDisplay object. This method initializes display.
     * 
     */
    KeyboardDisplay();

    /**
     * @brief Draw all keys on the keyboard in grey color.
     * 
     * @param keys Vector of keys to draw.
     */
    void drawKeys(std::vector<Key> keys);

    /**
     * @brief Draw single key in grey color.
     * 
     * @param key Key to draw.
     */
    void drawKey(Key key);
    
    /**
     * @brief Draw selected key in green color.
     * 
     * @param key Key to draw.
     */
    void drawSelectedKey(Key key);

private:
    const int KEY_HEIGHT = 20;

    const int KEY_WIDTH = 32;

    void drawKey(Key key, int color);

    /**
     * @brief Get x-axis position in pixels.
    */
    int getXPx(Vector2D position);

    /**
     * @brief Get y-axis position in pixels.
    */
    int getYPx(Vector2D position);

    Arduino_ILI9341* display;
};


#endif