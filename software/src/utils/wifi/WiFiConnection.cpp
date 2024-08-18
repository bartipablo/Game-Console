#include "WiFiConnection.h"

namespace wifi {

WiFiConnection* WiFiConnection::wifiConnection_ = nullptr;

WiFiConnection::WiFiConnection() {
    strcpy(this->lastSSID, "");
}

void WiFiConnection::init() {
    if (wifiConnection_ != nullptr) {
        return;
    }
    wifiConnection_ = new WiFiConnection();
} 

WiFiConnection* WiFiConnection::getInstance() {
    return wifiConnection_;
}

void WiFiConnection::connectToWiFi(const char* ssid) {
    WiFi.begin(ssid);
    strcpy(this->lastSSID, ssid);
}

void WiFiConnection::connectToWiFi(const char* ssid, const char* password) {
    WiFi.begin(ssid, password);
    strcpy(this->lastSSID, ssid);
}

void WiFiConnection::disconnect() {
    WiFi.disconnect();
    strcpy(this->lastSSID, "");
}

bool WiFiConnection::isConnected() {
    int connectionStatus = WiFi.status();
    return connectionStatus == WL_CONNECTED;
}

std::vector<WiFiNetwork> WiFiConnection::scanNetworks() {
    std::vector<WiFiNetwork> networks;

    int numNetworks = WiFi.scanNetworks();
    for (int i = 0; i < numNetworks; i++) {
        WiFiNetwork network(
            (char*) WiFi.SSID(i).c_str(),
            WiFi.RSSI(i),
            getWiFiEncriptionType(WiFi.encryptionType(i))
        );
        networks.push_back(network);
    }

    return networks;
}

const char* WiFiConnection::getLastSSID() {
    return lastSSID;
}

}