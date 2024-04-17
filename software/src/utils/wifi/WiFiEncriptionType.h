#ifndef WiFiEncriptionType_H
#define WiFiEncriptionType_H

#include <string>

/**
 * @brief An enum class that represents the different types of wifi encription.
 
*/
enum class WiFiEncriptionType {
    TKIP, /// (WPA)
    WEP,  
    CCMP, /// (WPA)
    NONE,
    AUTO,
    OTHER
};

WiFiEncriptionType getWiFiEncriptionType(int encriptionCode);

std::string toStringEncriptionType(WiFiEncriptionType encriptionType);

#endif