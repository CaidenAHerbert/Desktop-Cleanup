cmake_minimum_required(VERSION 3.26)
project(Desktop_Cleanup)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Desktop_Cleanup
        File.cpp
        File.h
        main.cpp)
