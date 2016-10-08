cmake_minimum_required(VERSION 3.6)
project(hackUPC_Fall_2016_MotTorrent)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    daemon/CMakeLists.txt
        commandport.cpp
        dimon.cpp
        main.cpp
        operations.cpp
        operations.h)

add_executable(hackUPC_Fall_2016_MotTorrent ${SOURCE_FILES})