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

#endif

#define ERROR -1
#define OK 1

#define NO_MESSAGE -1
#define NO_CONNECTION 0

typedef int EXIT_STATUS;
typedef int SOCKET;

#endif