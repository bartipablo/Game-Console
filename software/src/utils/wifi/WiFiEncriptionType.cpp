#include "WiFiEncriptionType.h"

namespace wifi {

WiFiEncriptionType getWiFiEncriptionType(int encriptionCode) {
    switch (encriptionCode) {
        case 2:
            return WiFiEncriptionType::TKIP;
        case 5:
            return WiFiEncriptionType::WEP;
        case 4:
            return WiFiEncriptionType::CCMP;
        case 7:
            return WiFiEncriptionType::NONE;
        case 8:
            return WiFiEncriptionType::AUTO;
        default:
            return WiFiEncriptionType::OTHER;
    }
}

std::string toStringEncriptionType(WiFiEncriptionType encriptionType) {
    switch (encriptionType) {
        case WiFiEncriptionType::TKIP:
            return "TKIP";
        case WiFiEncriptionType::WEP:
            return "WEP";
        case WiFiEncriptionType::CCMP:
            return "CCMP";
        case WiFiEncriptionType::NONE:
            return "NONE";
        case WiFiEncriptionType::AUTO:
            return "AUTO";
        case WiFiEncriptionType::OTHER:
            return "OTHER";
    }
    return "unknown";
}

}