//
// Created by bartipablo on 26.04.24.
//

#include "../Inc/SocketAddress.h"

SocketAddress::SocketAddress(uint32_t inAddress, uint16_t inPort) {
    getAsSockAddrIn()->sin_family = AF_INET;
    getAsSockAddrIn()->sin_addr.s_addr = htonl( inAddress );
    getAsSockAddrIn()->sin_port = htons( inPort );
}

SocketAddress::SocketAddress(const sockaddr &inSockAddr) {
    memcpy( &mSockAddr, &inSockAddr, sizeof( sockaddr ) );
}

size_t SocketAddress::getSize() const {
    return sizeof(sockaddr);
}

sockaddr_in* SocketAddress::getAsSockAddrIn() {
    return reinterpret_cast<sockaddr_in*>(& mSockAddr);
}