#include "InputBlocking.h"

InputBlocking::InputBlocking() {
    counter = 0;    
}

bool InputBlocking::isBlocked() {
    return counter != 0;
}

void InputBlocking::startBlocking(int blockedFramesNo) {
    if (blockedFramesNo < 0) return;
    counter = blockedFramesNo;
}

void InputBlocking::decrement() {
    if (counter <= 0) return;
    counter--;
}