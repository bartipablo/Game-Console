cmake_minimum_required(VERSION 3.25)
project(multiplayer)

set(CMAKE_CXX_STANDARD 23)

add_executable(multiplayer main.cpp pong/pong-game/Inc/Ball.h pong/pong-game/Src/Ball.cpp pong/pong-game/Inc/Paddles.h pong/pong-game/Src/Paddles.cpp
        common/Inc/SocketAddress.h
        common/Src/SocketAddress.cpp
)
