#include "SocketUDP.h"

SocketUDP::~SocketUDP() {
    close(mSocket);
}

EXIT_STATUS SocketUDP::init_() {
    if (mSocket != -1) {
        close(mSocket);
    }

    mSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (mSocket < 0) {
        return ERROR;
    }
    return OK;
}

int SocketUDP::sendTo_(const char *buffer, int size, SocketAddress &address) {
    int byteSendCount = sendto(mSocket, buffer, size, 0, address.addr(), address.addrLen());
    if (byteSendCount < 0) {
        return ERROR;
    }
    return byteSendCount;
}

int SocketUDP::receiveFrom_(char *buffer, int maxSize, SocketAddress &address) {
    socklen_t fromLength = address.addrLen();
    int byteReadCount = recvfrom(mSocket, buffer, maxSize, 0, address.addr(), &fromLength);
    if (byteReadCount < 0) {
        return ERROR;
    }
    return byteReadCount;
}