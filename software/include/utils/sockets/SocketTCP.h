#ifndef SOCKET_TCP_H
#define SOCKET_TCP_H

#include "Socket.h"

namespace sockets {

class SocketTCP : public Socket {

public:
    SocketTCP();

    SocketTCP(SOCKET inSocket);

    ~SocketTCP();

    EXIT_STATUS init_() override;

/**
 * Connect to a server by client.
 * @param address The address of the server.
 * @return EXIT_STATUS
*/
    EXIT_STATUS connect_(SocketAddress& address);

/**
 * Accept any connection from a client.
 * @return SOCKET
 * @return ERROR if the connection fails.
*/
    SOCKET accept_();

    SOCKET accept_(SocketAddress& address);

/**
 * Send data to the server.
 * @param buffer The data to send.
 * @param size The size of the data.
 * @return length of the data sent.
 * @return ERROR if the data can't be sent.
 */
    int send_(const char* buffer, int size);

/**
 * Receive data from the server.
 * @param buffer The buffer to store the data.
 * @param size The max size of the buffer.
 * @return length of the data received.
 * @return ERROR if the data can't be received.
 */
    int receive_(char* buffer, int size);

/**
 * Listen for incoming connections.
 * @param backlog The maximum length of the queue of pending connections.
 * @return EXIT_STATUS
 */
    EXIT_STATUS listen_(int backlog);
};

}

#endif