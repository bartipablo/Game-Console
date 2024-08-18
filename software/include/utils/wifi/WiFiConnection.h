#ifndef WiFiConnection_H
#define WiFiConnection_H

#include <vector>
#include <WiFi.h>

#include "WiFiEncriptionType.h"
#include "WiFiNetwork.h"

/**
 * @brief A class that is a singleton and wrapper for a wifi connection.
 * NOTE: Class currently does not provide a method to connect to a WEP-secured network.
 */
class WiFiConnection {
public:        
    WiFiConnection(const WiFiConnection&) = delete;

    void operator=(const WiFiConnection&) = delete;

    /**
     * @brief Initializes an singleton instance of wifi connection.
     */
    static void init();

    /**
     * @brief Gets the singleton instance of the WiFi connection class.
     */
    static WiFiConnection* getInstance();

    /**
     * @brief Connects to a wifi network.
     * 
     * The method connects to a OPEN (without the required password) wifi network with the provided ssid.
     * 
     * @param ssid The ssid of the wifi network to connect to.
     */
    void connectToWiFi(const char* ssid);

    /**
     * @brief Connects to a wifi network.
     * 
     * The method connects to a WPA-secured (password required) wifi network with the provided ssid and password.
     * 
     * @param ssid The ssid of the wifi network to connect to.
     * @param password The password of the wifi network to connect to.
     */
    void connectToWiFi(const char* ssid, const char* password);

    /**
     * @brief Disconnects from the current wifi network.
     * If we are connected to the network then we will be disconnected.
     * If we are not connected to the network the call will be ignored.
    */ 
    void disconnect();

    /**
     * @brief Checks if we are connected to a wifi network.
     * Caution: The method does not check if we have saved the wifi network's credentials.
     * 
     * @return True if we are connected to a wifi network, false otherwise.
     */
    bool isConnected();

    /**
     * @brief Gets the current wifi network's.
     * 
     * @return The vector of objects representing wifi networks.
     */
    std::vector<WiFiNetwork> scanNetworks();

    /**
     * @brief Gets the ssid of the last connected wifi network.
     * if we have not wifi network credentials the method will return an empty string.
     * 
     * @return The ssid of the last connected wifi network.
     */
    const char* getLastSSID();
    
private:
    WiFiConnection();

    char lastSSID[32];

    static WiFiConnection* wifiConnection_;
};

#endif