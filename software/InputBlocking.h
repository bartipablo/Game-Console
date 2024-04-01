#ifndef InputBlocking_H
#define InputBlocking_H

class InputBlocking {

public:
    InputBlocking();

    bool isBlocked();

    void startBlocking(int blockedFramesNo);

    void decrement();

private:
    int counter;
};


#endif
