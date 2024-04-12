#ifndef Application_H
#define Application_H

#include <string>

#include "../common/Vector2D.h"
#include "Icon.h"

class Application {

public:
    std::string getTitle() {
        return title;
    }

    virtual void start() = 0;

    virtual Icon* getIcon() = 0;

protected:
    std::string title;
};

#endif