//
// Created by bartipablo on 27.04.24.
//

#include "../Inc/TCPSocket.h"

int TCPSocket::Connect(const SocketAddress& inAddress) {
    int err = connect(mSocket, &inAddress.mSockAddr, inAddress.getSize());
    if (err < 0) {
        std::cout << "[SERVER] Error during TCPSocket::Connect." << std::endl;
        return ERROR;
    }
    return NO_ERROR;
}

int TCPSocket::Listen(int inBackLog) {
    int err = listen(mSocket, inBackLog);
    if (err < 0) {
        std::cout << "[SERVER] Error during TCPSocket::Listen." << std::endl;
        return ERROR;
    }
    return NO_ERROR;
}

TCPSocketPtr  TCPSocket::Accept(SocketAddress &inFromAddress) {
    int length = inFromAddress.getSize();
    SOCKET newSocket = accept(mSocket, &inFromAddress.mSockAddr, reinterpret_cast<socklen_t *>(&length));

    if (newSocket < 0) {
        std::cout << "[SERVER] Error during TCPSocket::Accept." << std::endl;
        return nullptr;
    }
    return TCPSocketPtr(new TCPSocket(newSocket));
}

int TCPSocket::Receive(void *inData, int inLen) {
    int bytesReceivedCount = recv(mSocket, static_cast<char*>(inData), inLen, 0);

    if (bytesReceivedCount < 0) {
        std::cout << "[SERVER] Error during TCPSocket::Receive." << std::endl;
        return ERROR;
    }
    return bytesReceivedCount;
}

int TCPSocket::Bind(const SocketAddress &inToAddress) {
    int err = bind(mSocket, &inToAddress.mSockAddr, inToAddress.getSize());

    if (err < 0) {
        std::cout << "[SERVER] Error during TCPSocket::Bind." << std::endl;
        return ERROR;
    }
    return NO_ERROR;
}

int	TCPSocket::Send( const void* inData, int inLen ) {
    int bytesSentCount = send( mSocket, static_cast< const char* >( inData ), inLen, 0 );
    if( bytesSentCount < 0 )
    {
        std::cout << "[SERVER] Error during TCPSocket::Send." << std::endl;
        return ERROR;
    }
    return NO_ERROR;
}

TCPSocket::~TCPSocket() {
    close(mSocket);
}

int TCPSocket::setNonBlockingMode(bool inShouldBeNonBlocking) {
    int flags = fcntl(mSocket, F_GETFL, 0);

    if (flags < 0) {
        std::cout << "[SERVER] Error during TCPSocket::setNonBlockingMode." << std::endl;
        return ERROR;
    }
    flags = inShouldBeNonBlocking ? (flags & ~O_NONBLOCK) : (flags | O_NONBLOCK);
    return (fcntl(mSocket, F_SETFL, flags) == 0);
}

