#ifndef PaintApplication_H
#define PaintApplication_H

#include "../Application.h" 
#include "PaintIcon.h"
#include "../../paint/PaintEngine.h"

class PaintApplication : public Application {
public:
    PaintApplication() {
        title = "Paint";
    }

    void start() override {
        PaintEngine* paintEngine = new PaintEngine();
        paintEngine->run();
        delete paintEngine;
    }

    Icon* getIcon() override {
        return new PaintIcon();
    }

private:

};

#endif
