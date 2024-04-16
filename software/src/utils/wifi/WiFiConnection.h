#ifndef WiFiConnection_H
#define WiFiConnection_H

#define WIFI_TIMEOUT_MS 10000

#include <string.h>
#include <vector>
#include <WiFi.h>

#include "WiFiEncriptionType.h"
#include "WiFiNetwork.h"

class WiFiConnection {
public:        
    WiFiConnection(const WiFiConnection&) = delete;

    void operator=(const WiFiConnection&) = delete;

    static void init();

    static WiFiConnection* getInstance();

    void connectToWiFi(const char* ssid);

    void connectToWiFi(const char* ssid, const char* password);

    void disconnect();

    bool isConnected();

    std::vector<WiFiNetwork> scanNetworks();

    const char* getLastSSID();
    
private:
    WiFiConnection();

    char lastSSID[32];

    static WiFiConnection* wifiConnection_;
};

#endif