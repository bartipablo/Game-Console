#ifndef SOCKET_ADDRESS_H
#define SOCKET_ADDRESS_H

#include "SocketHeader.h"

#include <string>

namespace sockets {

class SocketAddress {
    
public:
    SocketAddress(std::string host, int port);

    SocketAddress(int port);

    SocketAddress();

/**
 * Get references to a general pointer structure.
 * Used in functions that require a pointer to a general address structure (e.g. bind).
*/
    struct sockaddr* addr();

/*
* Get address length.
*/
    int addrLen();

    int getPort() const {
        return server_addr.sin_port;
    }

    void setPort(int port);

    bool operator==(const SocketAddress& other);

private:
    struct sockaddr_in server_addr;
};

}

#endif