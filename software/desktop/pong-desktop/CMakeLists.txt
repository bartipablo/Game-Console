cmake_minimum_required(VERSION 3.11)
project(pong-desktop-client)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
set(RAYLIB_VERSION 5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib
        DOWNLOAD_EXTRACT_TIMESTAMP OFF
        URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED)
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

# Our Project
set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/../)
include_directories(${CMAKE_SOURCE_DIR}/../../include/pong)
include_directories(${CMAKE_SOURCE_DIR}/../../include/utils/sockets)
include_directories(${CMAKE_SOURCE_DIR}/../../include/utils/streams)

# Find all .cpp files in the src directories
file(GLOB_RECURSE SRC_FILES
    ../../src/pong/*.cpp
    ../../src/utils/sockets/*.cpp
    ../../src/utils/streams/*.cpp
    DesktopClient.cpp
)

# Add executable target
add_executable(pong-desktop-client ${SRC_FILES})

target_link_libraries(pong-desktop-client raylib)

# Web Configurations
if (${PLATFORM} STREQUAL "Web")
    set_target_properties(pong-desktop-client PROPERTIES SUFFIX ".html")
endif()

# Checks if OSX and links appropriate frameworks
if (APPLE)
    target_link_libraries(pong-desktop-client "-framework IOKit")
    target_link_libraries(pong-desktop-client "-framework Cocoa")
    target_link_libraries(pong-desktop-client "-framework OpenGL")
endif()
