//
// Created by bartipablo on 27.04.24.
//

#ifndef MULTIPLAYER_SOCKETUTIL_H
#define MULTIPLAYER_SOCKETUTIL_H

#include "TCPSocket.h"

class SocketUtil {
    /**
     * static factory method to creating new sockets.
     * @return TCP socket pointer.
     */
    static TCPSocketPtr createTCPSocket();
};

#endif //MULTIPLAYER_SOCKETUTIL_H
