cmake_minimum_required(VERSION 3.6)
project(hackUPC_Fall_2016_MotTorrent)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        daemon/commandport.cpp
        daemon/dimon.cpp
        daemon/main.cpp
        daemon/operations.cpp
        daemon/operations.h)

INCLUDE_DIRECTORIES(
        /home/daniel/juackupc/libtorrent/binaries/include/
)

add_executable(hackUPC_Fall_2016_MotTorrent ${SOURCE_FILES})