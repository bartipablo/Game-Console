#ifndef SOCKETUDP_H
#define SOCKETUDP_H

#include "Socket.h"

class SocketUDP : public Socket {

public:
    ~SocketUDP();

    EXIT_STATUS init_() override;

/**
 * Send data to a specific address.
 * @param buffer The data to send.
 * @param size The size of the data.
 * @param address The address to send the data.
*/
    int sendTo_(const char* buffer, int size, SocketAddress& address);

/**
 * Receive data from a specific address.
 * @param buffer The buffer to store the data.
 * @param maxSize The max size of the buffer.
 * @param address The address to receive the data.
*/
    int receiveFrom_(char* buffer, int maxSize, SocketAddress& address);
};

#endif // SOCKETUDP_H
