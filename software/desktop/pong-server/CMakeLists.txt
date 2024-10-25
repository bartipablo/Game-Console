cmake_minimum_required(VERSION 3.0)

project(pong-server)

set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_BUILD_TYPE Release)

SET(CMAKE_BUILD_TYPE Debug)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/../)
include_directories(${CMAKE_SOURCE_DIR}/../../include/pong)
include_directories(${CMAKE_SOURCE_DIR}/../../include/utils)
include_directories(${CMAKE_SOURCE_DIR}/../../include/utils/sockets)
include_directories(${CMAKE_SOURCE_DIR}/../../include/utils/streams)


# Find all .cpp files in the src directories
file(GLOB_RECURSE SRC_FILES
    ../../src/pong/*.cpp
    ../../src/utils/sockets/*.cpp
    ../../src/utils/streams/*.cpp
    ../../src/utils/Timer.cpp
    Server.cpp
)


# Add executable target
add_executable(pong-server ${SRC_FILES})