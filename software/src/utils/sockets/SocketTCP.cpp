#include "SocketTCP.h"

namespace sockets {

SocketTCP::SocketTCP() {}

SocketTCP::~SocketTCP() {
    close(mSocket);
}

SocketTCP::SocketTCP(SOCKET inSocket) {
    mSocket = inSocket;
}

EXIT_STATUS SocketTCP::init_() {
    if (mSocket != -1) {
        close(mSocket);
    }

    mSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (mSocket < 0) {
        return ERROR;
    }
    return OK;
}

EXIT_STATUS SocketTCP::connect_(SocketAddress& address) {
    int err = connect(mSocket, address.addr(), address.addrLen());
    if (err < 0) {
        return ERROR;
    }
    return OK;
}

SOCKET SocketTCP::accept_(SocketAddress& address) {
    socklen_t fromLength = address.addrLen();

    int sck = accept(mSocket, address.addr(), &fromLength);
    if (sck < 0) {
        return ERROR;
    }
    return sck;
}

SOCKET SocketTCP::accept_() {
    int sck = accept(mSocket, nullptr, nullptr);
    if (sck < 0) {
        return ERROR;
    }
    return sck;
}

int SocketTCP::send_(const char* buffer, int size) {
    int sentByes = send(mSocket, buffer, size, 0);
    if (sentByes < 0) {
        return ERROR;
    }
    return sentByes;
}

int SocketTCP::receive_(char* buffer, int size) {
    int receivedBytes = recv(mSocket, buffer, size, 0);
    if (receivedBytes < 0) {
        return NO_MESSAGE;
    } else if (receivedBytes == 0) {
        return NO_CONNECTION;
    }
    return receivedBytes;
}

EXIT_STATUS SocketTCP::listen_(int backlog) {
    int err = listen(mSocket, backlog);
    if (err < 0) {
        return ERROR;
    }
    return OK;
}

}