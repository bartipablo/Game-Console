#ifndef Timer_H
#define Timer_H

#include <chrono>

/**
 * A timer class that allows timing.
 * It can be used to set latency and frame rate (alternative for sleep).
 */
class Timer {

public:
/**
 * @param duration the duration of the timer in milliseconds.
 */
    Timer(int duration) : duration(duration), startTime(std::chrono::high_resolution_clock::now()) {}

/**
 * Checks if the time has elapsed
 * @return true if the timer has expired. False otherwise.
 */
    bool isExpired();

/**
 * Resets the timer.
 */
    void reset();

private:
    int duration;

    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
};


#endif