#ifndef PongIcon_H
#define PongIcon_H

#include "Icon.h"

class PongIcon : public Icon {
public:
    PongIcon() : Icon{{110, 70}, 20, 20, 5} {}

    int getRGB565(int x, int y) override {
        if (x < 0 || x >= width || y < 0 || y >= height)
            return 0;
        return bitmap[x][y];
    }

private:
/**
 * Icon 20x20 represented by a 2D array of RGB565 values.
*/
    const unsigned short bitmap[20][20] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 38066, 48631, 27469, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 40179, 65535, 65535, 63422, 25356, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 50744, 65535, 65535, 65535, 31727, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 50744, 65535, 65535, 65535, 31727, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 50744, 65535, 65535, 65535, 31727, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 50744, 65535, 65535, 65535, 31727, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 50744, 65535, 65535, 65535, 31727, 0, 0, 48599, 61277, 54938, 35921, 35921, 27501, 23275, 19049, 10597, 10565, 0, 0},
        {0, 50744, 65535, 65535, 65535, 31727, 0, 31695, 65535, 65535, 65535, 52857, 46486, 46518, 27501, 33840, 19049, 12678, 8484, 0},
        {0, 50744, 65535, 65535, 65535, 31727, 0, 31695, 65535, 65535, 65535, 52857, 46486, 46518, 27501, 33840, 19049, 12678, 8484, 0},
        {0, 50744, 65535, 65535, 65535, 31727, 0, 0, 48599, 61277, 54938, 35921, 35921, 27501, 23275, 19049, 10597, 10565, 0, 0},
        {0, 50744, 65535, 65535, 65535, 31727, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 50744, 65535, 65535, 65535, 31727, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 50744, 65535, 65535, 65535, 31727, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 50744, 65535, 65535, 65535, 31727, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 40179, 65535, 65535, 63422, 25356, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 38066, 48631, 27469, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
};

#endif