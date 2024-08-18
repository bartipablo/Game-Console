#ifndef WindowsArrow_H
#define WindowsArrow_H

#include <pgmspace.h>

#include "CursorShape.h"
#include "Color.h"

namespace cursor {

/**
 * @brief Class representing a Windows arrow cursor.
 */
class WindowsArrow : public CursorShape {

public:
/**
 * @brief Construct a new Windows Arrow object
 * Constructor inits vector of pixels for windows arrow.
*/
    WindowsArrow();


};

}

#endif