//
// Created by bartipablo on 27.04.24.
//

#ifndef MULTIPLAYER_TCPSOCKET_H
#define MULTIPLAYER_TCPSOCKET_H

#include <sys/socket.h>
#include <sys/types.h>
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>
#include <memory>
#include <fcntl.h>

#include "./SocketAddress.h"

typedef int SOCKET;

#define NO_ERROR 0;
#define ERROR -1;

/**
 * @class TCPSocket
 *
 * @brief Class representing a TCP socket.
 *
 * The TCPSocket class provides wrapper for creating, connecting, binding, listening, accepting connections,
 * sending, and receiving data over TCP/IP sockets.
 */
class TCPSocket {
public:
    /**
     * Destructor.
     * Closes the socket associated with the TCPSocket object.
     */
    ~TCPSocket();

    /**
     * Connects the socket to the specified address.
     *
     * @param inAddress The address to connect to, represented as a SocketAddress object.
     * @return An integer representing the outcome of the operation (NO_ERROR or ERROR).
     */
    int Connect(const SocketAddress& inAddress);

    /**
     * Binds the socket to the specified local address.
     *
     * @param inToAddress The local address to bind to, represented as a SocketAddress object.
     * @return An integer representing the outcome of the operation (NO_ERROR or ERROR).
     */
    int Bind(const SocketAddress& inToAddress);

    /**
     * Listens for incoming connections on the socket.
     *
     * @param inBackLog The maximum length of the queue of pending connections.
     * @return An integer representing the outcome of the operation (NO_ERROR or ERROR).
     */
    int Listen(int inBackLog = 32);

    /**
     * Accepts an incoming connection request.
     *
     * @param inFromAddress The address from which the connection request originated.
     * @return A shared pointer to a TCPSocket object representing the accepted connection, or nullptr on error.
     */
    std::shared_ptr<TCPSocket> Accept(SocketAddress& inFromAddress);

    /**
     * Sends data over the socket.
     *
     * @param inData A pointer to the data to be sent.
     * @param inLen The length of the data to be sent.
     * @return An integer representing the number of bytes sent, or an error code if an error occurs.
     */
    int Send(const void* inData, int inLen);

    /**
     * Receives data from the socket.
     *
     * @param inBuffer A pointer to the buffer where the received data will be stored.
     * @param inLen The maximum length of the buffer.
     * @return An integer representing the number of bytes received, or an error code if an error occurs.
     */
    int Receive(void* inBuffer, int inLen);

    /**
 *
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
     * Creates a TCPSocket object with the specified socket descriptor.
     *
     * @param inSocket The socket descriptor associated with the TCPSocket object.
     */
    explicit TCPSocket(SOCKET inSocket) : mSocket(inSocket) {}

    SOCKET mSocket; ///< The socket descriptor associated with the TCPSocket object.
};
typedef std::shared_ptr<TCPSocket> TCPSocketPtr;


#endif //MULTIPLAYER_TCPSOCKET_H
