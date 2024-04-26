//
// Created by bartipablo on 26.04.24.
//

#ifndef MULTIPLAYER_SOCKETADDRESS_H
#define MULTIPLAYER_SOCKETADDRESS_H

#include <cstdint>
#include <cstring>
#include <netinet/in.h>
#include <string>
#include <memory>

#include "TCPSocket.h"

/**
 * @class SocketAddress
 *
 * @brief Class representing a socket address.
 *
 * Typesafe wrapper for socket address.
 */
class SocketAddress {

public:
/**
 * Constructor creating a socket address based on a specified IP address (in network order) and port.
 * Constructor automatically sets the address family to AF_INET (IPv4 address).
 *
 * @param inAddress The IP address in network order (32-bit unsigned integer).
 * @param inPort The port number in network order (16-bit unsigned integer).
 */
    SocketAddress(uint32_t inAddress, uint16_t inPort);

    /**
 * Constructor creating a socket address copied sockaddr structure.
 *
 * @param inSockAddr The sockaddr structure containing information about the address and port.
 */
    explicit SocketAddress(const sockaddr& inSockAddr);

    [[nodiscard]] size_t getSize() const;

private:
    friend class TCPSocket;

    sockaddr mSockAddr;

    sockaddr_in* getAsSockAddrIn();
};
typedef std::shared_ptr<SocketAddress> SocketAddressPtr;

#endif //MULTIPLAYER_SOCKETADDRESS_H
