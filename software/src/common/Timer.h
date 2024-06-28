#ifndef Timer_H
#define Timer_H

#include <chrono>

class Timer {

public:
    Timer(int duration) : duration(duration), startTime(std::chrono::high_resolution_clock::now()) {}

    bool isExpired();

    void reset();

private:
    int duration;

    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
};


#endif