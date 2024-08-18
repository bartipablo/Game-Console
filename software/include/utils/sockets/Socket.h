#ifndef SOCKET_H
#define SOCKET_H

#include "SocketHeader.h"
#include "SocketAddress.h"

namespace sockets {


class Socket {

public:
    /**
     * Initialize the new socket. 
     * This function assigns new native socket to Socket object. 
     * @return ERROR if the socket can't be created.
     * @return OK if the socket is created.
     */
    virtual EXIT_STATUS init_() = 0;

    virtual ~Socket() = default;

    /**
     * Bind the socket to a specific address.
     * CAUTION: Client doesn't should call bind method.
     * @param address The address to bind.
     * @return EXIT_STATUS
    */
    EXIT_STATUS bind_(SocketAddress* address);
    
    /**
     * Set the socket to non-blocking mode.
     * @param inShouldBeNonBlocking True if the socket should be non-blocking.
     * @param inShouldBeNonBlocking False if the socket should be blocking.
     */
    void setNonBlocking(bool shouldBeBlocking);

    /**
     * function returns the current address for the specified socket.
     * @param address to which it will be assigned.
     * @return EXIT_STATUS
     */
    EXIT_STATUS getSocketName_(SocketAddress* address);

    /**
     * Close the socket.
     * @return EXIT_STATUS
     */
    EXIT_STATUS close_();

protected:
    SOCKET mSocket = -1;
};

}

#endif
