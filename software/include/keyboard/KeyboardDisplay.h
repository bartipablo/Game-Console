#ifndef KeyboardDisplay_H
#define KeyboardDisplay_H

#include <vector>

#include "Keyboard.h"
#include "DigitalLCD.h"
#include "Color.h"

namespace keyboarddisplay {

constexpr int KEY_HEIGHT = 20; // < px

constexpr int KEY_WIDTH = 32; // < px

/**
 * @brief Draw all keys on the keyboard in grey color.
 * 
 * @param keys Vector of keys to draw.
 */
void drawKeys(std::vector<keyboard::Key> keys);

/**
 * @brief Draw single key in grey color.
 * 
 * @param key Key to draw.
 */
void drawKey(keyboard::Key key);

/**
 * @brief Draw selected key in green color.
 * 
 * @param key Key to draw.
 */
void drawSelectedKey(keyboard::Key key);

void drawKey(keyboard::Key key, int color);

/**
 * @brief Get x-axis position in pixels.
*/
int getXPx(Vector2D position);

/**
 * @brief Get y-axis position in pixels.
*/
int getYPx(Vector2D position);
}

#endif