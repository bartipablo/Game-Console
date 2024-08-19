#ifndef PONG_SOCKET_TCP_H
#define PONG_SOCKET_TCP_H

#include <thread>
#include <chrono>

#include "SocketTCP.h"
#include "Communicates.h"
#include "InputMemoryStream.h"
#include "OutputMemoryStream.h"

namespace pong {

/**
 * The PongSocketTCP class represents a TCP socket for the Pong game.
 * Class contains a specific methods for communication between server and client for the pong game.
 */
class PongSocketTCP : public sockets::SocketTCP {

public:
    PongSocketTCP();

    PongSocketTCP(sockets::SOCKET inSocket);

/**
 * Send a specific communicate to the other side.
 * @param request The communicate to send.
 * @see Communicates
*/
    void sendCommunicate(Communicates request);

/**
 * Receive a specific communicate from the other side.
 * if no communicate is sent, the function return Communicates::None (in non-blocking mode).
 * @return The received communicate.
 * @see Communicates
 */
    Communicates receiveCommunicate();

/**
 * recive a UDP socket port (from client to server).
 * @param socketAddress The address of the client.
 * @param timeout The time to wait for the port (10 * timeout [ms]).
 */
    bool receivePortUDP(sockets::SocketAddress* socketAddress, int timeout);

/**
 * Send a UDP socket port (from client to server).
 * @param port The port to send.
 */
    void sendPortUDP(int port);
};

}


#endif //PONG_SOCKET_TCP_H
