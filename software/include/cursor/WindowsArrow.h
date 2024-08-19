#ifndef WindowsArrow_H
#define WindowsArrow_H

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

    /** The arrow is represented by a 19x12 matrix of characters.
    * '0' - no pixel
    * '1' - black pixel
    * '2' - white pixel
    */
    static const char arrowCharRepresentation[19][12];
};

}

#endif