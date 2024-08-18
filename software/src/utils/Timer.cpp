#include "Timer.h"


bool Timer::isExpired() {
    auto now = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = now - startTime;
    return elapsed.count() >= duration;
}


void Timer::reset() {
    startTime = std::chrono::high_resolution_clock::now();
}