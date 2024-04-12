#ifndef NotepadIcon_H
#define NotepadIcon_H

#include "../Icon.h"

class NotepadIcon : public Icon {
public:
    NotepadIcon() {
        width = 20;
        height = 20;
        pixelSize = 5;
        position = Vector2D(110, 70);
    }

    int getRGB565(int x, int y) override {
        if (x < 0 || x >= width || y < 0 || y >= height)
            return 0;
        return bitmap[x][y];
    }

private:
    const unsigned short bitmap[20][20] = {
        {18983, 18983, 18983, 18983, 18983, 18983, 18983, 18983, 18983, 18983, 18983, 18983, 18983, 18983, 21031, 0, 0, 0, 0, 0},
        {18983, 44405, 54970, 54970, 54970, 54970, 54970, 54970, 54970, 54970, 54970, 54970, 54970, 38066, 21031, 0, 0, 0, 0, 0},
        {18983, 54970, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 44405, 21031, 0, 0, 0, 0, 0},
        {18983, 54970, 65535, 0, 0, 0, 0, 0, 0, 0, 0, 29614, 65535, 44405, 21031, 0, 0, 0, 0, 0},
        {18983, 54970, 65535, 50744, 50744, 50744, 50744, 50744, 50744, 50744, 50744, 54970, 65535, 44405, 21031, 0, 21031, 21031, 14657, 0},
        {18983, 54970, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 44405, 21031, 14657, 44405, 44405, 38066, 14657},
        {18983, 54970, 65535, 18983, 18983, 18983, 18983, 18983, 18983, 18983, 18983, 29614, 65535, 44405, 18983, 18983, 65503, 65535, 54970, 18983},
        {18983, 54970, 65535, 50744, 50744, 50744, 50744, 50744, 50744, 50744, 50744, 54970, 65535, 44405, 33542, 64706, 64706, 65369, 54970, 18983},
        {18983, 54970, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 44405, 48301, 60514, 64706, 64706, 48301, 29614, 6338},
        {18983, 54970, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65503, 52857, 48301, 60514, 64706, 64706, 54241, 33542, 14657, 0},
        {18983, 54970, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65503, 54970, 33542, 60514, 64706, 64674, 60514, 21031, 14657, 0, 0},
        {18983, 54970, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 52857, 33542, 64706, 64706, 64706, 60514, 18983, 4225, 0, 0, 0},
        {18983, 54970, 65535, 65535, 65535, 65535, 65535, 65535, 44405, 48301, 60514, 64706, 64706, 52161, 29382, 6338, 32, 0, 0, 0},
        {18983, 54970, 65535, 65535, 65535, 65535, 65535, 44405, 52625, 65004, 64706, 64706, 52161, 33542, 21031, 0, 0, 0, 0, 0},
        {18983, 54970, 65535, 65535, 65535, 65535, 65535, 18983, 63124, 65105, 64772, 60514, 42061, 23275, 21031, 0, 0, 0, 0, 0},
        {18983, 54970, 65535, 65535, 65535, 65535, 65535, 18983, 63124, 65237, 63124, 21031, 59196, 44405, 21031, 0, 0, 0, 0, 0},
        {18983, 54970, 65535, 25289, 25289, 25289, 25289, 18983, 25289, 25289, 29614, 65503, 65535, 44405, 21031, 0, 0, 0, 0, 0},
        {18983, 54970, 65535, 52857, 52857, 52857, 52857, 52857, 52857, 52857, 54970, 65535, 65535, 44405, 21031, 0, 0, 0, 0, 0},
        {18983, 44405, 54970, 54970, 54970, 54970, 54970, 54970, 54970, 54970, 54970, 54970, 54970, 38066, 21031, 0, 0, 0, 0, 0},
        {18983, 18983, 18983, 18983, 18983, 18983, 18983, 18983, 18983, 18983, 18983, 18983, 18983, 18983, 21031, 0, 0, 0, 0, 0}
    };
};

#endif
