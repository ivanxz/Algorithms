cmake_minimum_required(VERSION 3.17)
project(Algorithms)

set (VERSION_MAJOR 1)
set (VERSION_MINOR 0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MACOSX_RPATH 0)
add_subdirectory(src)