#ifndef TetrisApplication_H
#define TetrisApplication_H

#include "../Application.h" 
#include "TetrisIcon.h"
#include "../../tetris/TetrisEngine.h"

class TetrisApplication : public Application {
public:
    TetrisApplication() {
        title = "Tetris";
    }

    void start() override {
        TetrisEngine* tetrisEngine = new TetrisEngine();
        tetrisEngine->run();
        delete tetrisEngine;
    }

    Icon* getIcon() override {
        return new TetrisIcon();
    }

private:

};

#endif
