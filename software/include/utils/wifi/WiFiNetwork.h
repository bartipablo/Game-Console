#ifndef WiFiNetwork_H
#define WiFiNetwork_H

#include <cstring>

#include "WiFiEncriptionType.h"

/**
 * @brief A class that represents a wifi network.
 */
class WiFiNetwork {

public:
    WiFiNetwork(const char* ssid, const int rssi, const WiFiEncriptionType encryptionType) : rssi(rssi), encriptionType(encryptionType) {
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

    const int rssi;

    const WiFiEncriptionType encriptionType;
    
};

#endif