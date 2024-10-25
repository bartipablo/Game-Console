#ifndef SnakeIcon_H
#define SnakeIcon_H

#include "Icon.h"

namespace snake {

class SnakeIcon : public Icon {
public:
    SnakeIcon() : Icon{{110, 70}, 20, 20, 5} {}

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
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 38387, 30063, 30063, 30063, 30063, 50776, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 34225, 9771, 18151, 16073, 13993, 16073, 11656, 46518, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 34097, 9738, 11915, 13993, 7626, 9738, 16042, 32144, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 59228, 44662, 23885, 9771, 9835, 9835, 7594, 9707, 16042, 32144, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {40211, 34321, 9706, 9803, 9835, 7496, 9835, 11883, 9835, 9835, 32144, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {59228, 5158, 5222, 5222, 5222, 9770, 11883, 9674, 7465, 18087, 32144, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 65178, 48335, 32144, 32144, 32144, 32144, 21804, 42598, 28361, 32144, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 64918, 64918, 0, 0, 0, 40211, 42610, 46790, 30439, 32144, 0, 59228, 53018, 53018, 53018, 53018, 59260, 0, 0},
        {0, 64756, 64755, 0, 0, 50905, 46740, 46790, 44807, 22026, 50872, 55002, 40563, 11688, 9609, 13799, 9641, 36433, 50905, 0},
        {0, 35856, 54840, 0, 48823, 42598, 38536, 34376, 23976, 7400, 44629, 36306, 11592, 11818, 9674, 13767, 11657, 36433, 52985, 0},
        {0, 0, 0, 0, 30063, 53061, 42790, 13961, 9771, 18087, 9771, 13929, 16008, 9641, 55066, 59260, 59260, 0, 0, 0},
        {0, 0, 0, 0, 0, 30063, 30063, 30063, 30096, 30063, 30063, 30063, 30063, 55066, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
};

}

#endif