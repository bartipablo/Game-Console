#ifndef SOCKET_ADDRESS_H
#define SOCKET_ADDRESS_H

#include "SocketHeader.h"

#include <string>

class SocketAddress {
    
public:
    SocketAddress(std::string host, int port);

    SocketAddress(int port);

/**
 * Get references to a general pointer structure.
 * Used in functions that require a pointer to a general address structure (e.g. bind).
*/
    struct sockaddr* addr();

    int addrLen();

private:
    struct sockaddr_in server_addr;
};


#endif