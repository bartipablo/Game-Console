#ifndef Battery_H
#define Battery_H

#include "Adafruit_LC709203F.h"
#include "ForbiddenOperation.h"


/**
 * This class should be used to get information about the battery state.
 * Implementing the Singleton pattern.
 */
class Battery {
    
public:
    Battery(const Battery &) = delete;

    void operator=(const Battery &) = delete;

    static void init(int thermistorB, lc709203_adjustment_t packSize);

    static Battery *getInstance();

    float getVoltage();

    float getPercentCharged();

    float getTemperature();

private:
    /*
    * @param thermistorB The value of the thermistor B.
    * @param packSize The size of the battery pack.
    */
    Battery(int thermistorB, lc709203_adjustment_t packSize);

    static Battery *battery_;

    Adafruit_LC709203F lc;
};

#endif