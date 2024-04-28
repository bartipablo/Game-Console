//
// Created by bartipablo on 27.04.24.
//

#ifndef MULTIPLAYER_UDPSOCKET_H
#define MULTIPLAYER_UDPSOCKET_H

#include <memory>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>

#include "SocketAddress.h"
#include "SocketUtil.h"

typedef int SOCKET;

#define NO_ERROR 0;
#define ERROR -1;

/**
 * @class UDPSocket
 *
 * @brief Class representing a UDP socket.
 *
 * The UDPSocket class provides functionalities for creating, binding, sending, and receiving data over UDP/IP sockets.
 */
class UDPSocket {
public:
    /**
     * Destructor.
     * Closes the socket associated with the UDPSocket object.
     */
    ~UDPSocket();

    /**
     * Binds the socket to the specified address.
     *
     * @param inToAddress The local address to bind to, represented as a SocketAddress object.
     * @return An integer representing the outcome of the operation (NO_ERROR or ERROR).
     */
    int Bind(const SocketAddress& inToAddress);

    /**
     * Sends data over the socket to the specified destination address.
     *
     * @param inData A pointer to the data to be sent.
     * @param inLen The length of the data to be sent.
     * @param inTo The destination address to send the data to, represented as a SocketAddress object.
     * @return An integer representing the number of bytes sent, or an error code if an error occurs.
     */
    int SendTo(const void* inData, int inLen, const SocketAddress& inTo);

    /**
     * Receives data from the socket, along with information about the sender.
     *
     * @param inBuffer A pointer to the buffer where the received data will be stored.
     * @param inLen The maximum length of the buffer.
     * @param outFrom Reference to a SocketAddress object where the sender's address information will be stored.
     * @return An integer representing the number of bytes received, or an error code if an error occurs.
     */
    int ReceiveFrom(void* inBuffer, int inLen, SocketAddress& outFrom);

    /**
    * This function allows you to set the non-blocking mode for the socket. In non-blocking mode, socket operations such as sending and receiving data will return immediately, even if they would normally block. This can be useful in scenarios where you want to perform other tasks while waiting for socket operations to complete.
    *
    * @param inShouldBeNonBlocking A boolean value indicating whether the socket should be set to non-blocking mode (`true`) or blocking mode (`false`).
    * @return An integer representing the outcome of the operation:
            *         - `NO_ERROR` if the operation is successful and the socket's blocking mode is set accordingly.
    *         - `ERROR` if an error occurs during the operation.
    */
    int setNonBlockingMode(bool inShouldBeNonBlocking);

private:
    friend class SocketUtil;

    /**
     * Constructor.
     * Creates a UDPSocket object with the specified socket descriptor.
     *
     * @param inSocket The socket descriptor associated with the UDPSocket object.
     */
    explicit UDPSocket(SOCKET inSocket) : mSocket(inSocket) {}

    SOCKET mSocket; ///< The socket descriptor associated with the UDPSocket object.
};

/**
 * @typedef UDPSocketPtr
 * @brief Shared pointer to a UDPSocket object.
 */
typedef std::shared_ptr<UDPSocket> UDPSocketPtr;

#endif //MULTIPLAYER_UDPSOCKET_H
