cmake_minimum_required(VERSION 3.25)
project(multiplayer)

set(CMAKE_CXX_STANDARD 23)

add_executable(multiplayer main.cpp pong/pong-game/Inc/Ball.h pong/pong-game/Src/Ball.cpp pong/pong-game/Inc/Paddles.h pong/pong-game/Src/Paddles.cpp
        common/Inc/SocketAddress.h
        common/Src/SocketAddress.cpp
        common/Inc/SocketAddressFactory.h
        common/Src/SocketAddressFactory.cpp
        common/Inc/TCPSocket.h
        common/Src/TCPSocket.cpp
        common/Inc/SocketUtil.h
        common/Src/SocketUtil.cpp
        common/Inc/UDPSocket.h
        common/Src/UDPSocket.cpp
)
