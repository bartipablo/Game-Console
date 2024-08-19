#include "Socket.h"

namespace sockets {

EXIT_STATUS Socket::bind_(SocketAddress* address) {
    int err = bind(mSocket, address->addr(), address->addrLen());
    if (err < 0) {
        return ERROR;
    }
    return OK;
}

void Socket::setNonBlocking(bool shouldBeBlocking) {
    int flags = fcntl(mSocket, F_GETFL, 0);
    if (shouldBeBlocking) {
        fcntl(mSocket, F_SETFL, flags | O_NONBLOCK);
    } else {
        fcntl(mSocket, F_SETFL, flags & ~O_NONBLOCK);
    }
}

EXIT_STATUS Socket::getSocketName_(SocketAddress* address) {
    socklen_t fromLength = address->addrLen();
    int err = getsockname(mSocket, address->addr(), &fromLength);
    if (err < 0) {
        return ERROR;
    }
    return OK;
}

EXIT_STATUS Socket::close_() {
    int err = close(mSocket);
    if (err < 0) {
        return ERROR;
    }
    return OK;
}

}