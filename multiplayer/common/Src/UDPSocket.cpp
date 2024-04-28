//
// Created by bartipablo on 27.04.24.
//

#include "../Inc/UDPSocket.h"

int UDPSocket::Bind(const SocketAddress &inToAddress) {
    int err = bind(mSocket, &inToAddress.mSockAddr, inToAddress.getSize());
    if (err < 0) {
        std::cout << "[SERVER] Error during UDPSocket::Bind." << std::endl;
        return ERROR;
    }
    return NO_ERROR;
}

int UDPSocket::ReceiveFrom(void *inBuffer, int inLen, SocketAddress &outFrom) {
    int fromLength = outFrom.getSize();
    int readByteCount = recvfrom(
            mSocket,
            static_cast<char*> (inBuffer),
            inLen,
            0, &outFrom.mSockAddr,
            reinterpret_cast<socklen_t *>(&fromLength)
        );

    if (readByteCount  < 0) {
        std::cout << "[SERVER] Error during UDPSocket::ReceiveFrom." << std::endl;
        return ERROR;
    }
    return readByteCount;
}

int UDPSocket::SendTo(const void *inData, int inLen, const SocketAddress &inTo) {

    int byteSentCount = sendto(
            mSocket,
            static_cast<const char*> (inData),
            inLen,
            0, &inTo.mSockAddr,
            inTo.getSize()
        );

    if (byteSentCount < 0) {
        std::cout << "[SERVER] Error during UDPSocket::SendTo." << std::endl;
        return ERROR;
    }
    return byteSentCount;
}

UDPSocket::~UDPSocket() {
    close(mSocket);
}

int UDPSocket::setNonBlockingMode(bool inShouldBeNonBlocking) {
    int flags = fcntl(mSocket, F_GETFL, 0);

    if (flags < 0) {
        std::cout << "[SERVER] Error during TCPSocket::setNonBlockingMode." << std::endl;
        return ERROR;
    }
    flags = inShouldBeNonBlocking ? (flags & ~O_NONBLOCK) : (flags | O_NONBLOCK);
    return (fcntl(mSocket, F_SETFL, flags) == 0);
}