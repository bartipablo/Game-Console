cmake_minimum_required(VERSION 3.0)

project(pong-server)

set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_BUILD_TYPE Release)

SET(CMAKE_BUILD_TYPE Debug)

add_executable(pong-server Server.cpp
        ../pong-game/Ball.cpp
        ../pong-game/Communicates.h
        ../pong-game/Move.cpp
        ../pong-game/Paddle.cpp
        ../pong-game/PongSocketTCP.cpp
        ../pong-game/Score.cpp
        ../pong-game/Table.h
        ../sockets/Socket.cpp
        ../sockets/SocketAddress.cpp
        ../sockets/SocketHeader.h
        ../sockets/SocketTCP.cpp
        ../sockets/SocketUDP.cpp
        ../streams/InputMemoryStream.cpp
        ../streams/OutputMemoryStream.cpp
        ../streams/Serializable.h)