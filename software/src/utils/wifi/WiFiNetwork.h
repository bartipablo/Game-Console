#ifndef WiFiNetwork_H
#define WiFiNetwork_H

#include <string>

#include "WiFiEncriptionType.h"

/**
 * @brief A class that represents a wifi network.
 */
class WiFiNetwork {

public:
    WiFiNetwork(char* ssid, int rssi, WiFiEncriptionType encryptionType) : rssi(rssi), encriptionType(encryptionType) {
        strcpy(this->ssid, ssid);
    }

    const char* getSSID() const {
        return ssid;
    }

    int getRSSI() const {
        return rssi;
    }

    WiFiEncriptionType getEncryptionType() const {
        return encriptionType;
    }

private:
    char ssid[32];

    int rssi;

    WiFiEncriptionType encriptionType;
    
};

#endif