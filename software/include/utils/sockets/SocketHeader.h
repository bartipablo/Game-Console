#ifndef SOCKET_HEADER_H
#define SOCKET_HEADER_H

#ifdef ARDUINO

#include <lwip/sockets.h>

#else  //for POSIX systems.

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

#endif

namespace sockets {

constexpr int ERROR {-1};
constexpr int OK {1};

constexpr int NO_MESSAGE {-1};
constexpr int NO_CONNECTION {0};

using EXIT_STATUS = int;
using SOCKET = int;
}

#endif