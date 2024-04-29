#include "Socket.h"

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