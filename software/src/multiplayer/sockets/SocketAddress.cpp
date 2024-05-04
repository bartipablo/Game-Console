#include "SocketAddress.h"

SocketAddress::SocketAddress(std::string host, int port) {
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host.c_str(), &server_addr.sin_addr);
}

SocketAddress::SocketAddress(int port) {
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;
}

SocketAddress::SocketAddress() {
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(0);
    server_addr.sin_addr.s_addr = INADDR_ANY;
}

struct sockaddr* SocketAddress::addr() {
    return (struct sockaddr*)&server_addr;
}

int SocketAddress::addrLen() {
    return sizeof(server_addr);
}

void SocketAddress::setPort(int port) {
    server_addr.sin_port = port;
}

bool SocketAddress::operator==(const SocketAddress &other) {
    if (server_addr.sin_port != other.server_addr.sin_port) return false;
    if (server_addr.sin_addr.s_addr != other.server_addr.sin_addr.s_addr) return false;
    if (server_addr.sin_family != other.server_addr.sin_family) return false;

    return true;
}
