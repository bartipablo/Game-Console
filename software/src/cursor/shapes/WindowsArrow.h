#ifndef WindowsArrow_H
#define WindowsArrow_H

#include "CursorShape.h"
#include "../../common/Color.h"

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

private:

/** The arrow is represented by a 19x12 matrix of characters.
* '0' - no pixel
* '1' - black pixel
* '2' - white pixel
*/
char arrowCharRepresentation[19][12] = {
        {'1','0','0','0','0','0','0','0','0','0','0','0'},
        {'1','1','0','0','0','0','0','0','0','0','0','0'},
        {'1','2','1','0','0','0','0','0','0','0','0','0'},
        {'1','2','2','1','0','0','0','0','0','0','0','0'},
        {'1','2','2','2','1','0','0','0','0','0','0','0'},
        {'2','2','2','2','2','1','0','0','0','0','0','0'},
        {'1','2','2','2','2','2','1','0','0','0','0','0'},
        {'1','2','2','2','2','2','2','1','0','0','0','0'},
        {'1','2','2','2','2','2','2','2','1','0','0','0'},
        {'1','2','2','2','2','2','2','2','2','1','0','0'},
        {'1','2','2','2','2','2','2','2','2','2','1','0'},
        {'1','2','2','2','2','2','2','2','2','2','2','1'},
        {'1','2','2','2','2','2','2','2','1','1','1','0'},
        {'1','2','2','2','2','2','2','1','0','0','0','0'},
        {'1','2','2','2','1','2','2','2','1','0','0','0'},
        {'1','2','2','1','0','1','2','2','1','0','0','0'},
        {'1','2','1','0','0','0','1','2','2','1','0','0'},
        {'1','1','0','0','0','0','1','2','2','1','0','0'},
        {'0','0','0','0','0','0','0','1','1','0','0','0'}
    };
};

#endif