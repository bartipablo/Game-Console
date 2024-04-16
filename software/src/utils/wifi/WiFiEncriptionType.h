#ifndef WiFiEncriptionType_H
#define WiFiEncriptionType_H

#include <string>

enum class WiFiEncriptionType {
    TKIP,
    WEP,
    CCMP,
    NONE,
    AUTO,
    OTHER
};

WiFiEncriptionType getWiFiEncriptionType(int encriptionCode);

std::string toStringEncriptionType(WiFiEncriptionType encriptionType);

#endif