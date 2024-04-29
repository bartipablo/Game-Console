#include "SocketAddress.h"

SocketAddress::SocketAddress(std::string host, int port) {
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(host.c_str());
}

SocketAddress::SocketAddress(int port) {
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;
}

struct sockaddr* SocketAddress::addr() {
    return (struct sockaddr*)&server_addr;
}

int SocketAddress::addrLen() {
    return sizeof(server_addr);
}