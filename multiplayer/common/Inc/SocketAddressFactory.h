//
// Created by bartipablo on 27.04.24.
//

#ifndef MULTIPLAYER_SOCKETADDRESSFACTORY_H
#define MULTIPLAYER_SOCKETADDRESSFACTORY_H

#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>

#include "SocketAddress.h"

/**
 * @class SocketAddressFactory
 *
 * @brief Factory class for creating SocketAddress objects.
 */
class SocketAddressFactory {

/**
  * Create a SocketAddress object from a string representing an IPv4 address and port.
  *
  * @param inString The string representation of the IPv4 address and port (format: "host:port").
  *                 If no port is specified, the port defaults to 0.
  * @return A shared pointer to the created SocketAddress object, or nullptr if creation fails.
  */
    static SocketAddressPtr createIPv4FromString(const std::string inString);
};

#endif //MULTIPLAYER_SOCKETADDRESSFACTORY_H
