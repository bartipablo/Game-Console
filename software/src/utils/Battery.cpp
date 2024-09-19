#include "Battery.h"

Battery* Battery::battery_ = nullptr;


Battery::Battery(int thermistorB, lc709203_adjustment_t PackSize) {
    lc.begin();
    lc.setThermistorB(thermistorB);
    lc.setPackSize(LC709203F_APA_500MAH);
}


void Battery::init(int thermistorB, lc709203_adjustment_t PackSize) {
    battery_ = new Battery(thermistorB, PackSize);
}


Battery *Battery::getInstance() {
    if (battery_ == nullptr) {
        throw ForbiddenOperation("Battery not initialized");
    }
    return battery_;
}


float Battery::getVoltage() {
    return lc.cellVoltage();
}


float Battery::getPercentCharged() {
    return lc.cellPercent();
}


float Battery::getTemperature() {
    return lc.getCellTemperature();
}