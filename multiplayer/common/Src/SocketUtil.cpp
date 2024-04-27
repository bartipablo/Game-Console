//
// Created by bartipablo on 27.04.24.
//

#include "../Inc/SocketUtil.h"

TCPSocketPtr SocketUtil::createTCPSocket() {
    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);

    if (s < 0) {
        std::cout << "[SERVER] Error during SocketUtil::createTCPSocket." << std::endl;
        return nullptr;
    }
    return TCPSocketPtr(new TCPSocket(s));
}

