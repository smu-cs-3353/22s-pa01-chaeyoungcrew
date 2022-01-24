cmake_minimum_required(VERSION 3.17)
project(22s_pa01)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_RELEASE -O3)

add_executable(pa01 src/main.cpp src/Art.cpp src/Wall.cpp src/DSLinkedList.h)
add_executable(pa01_test src/test.cpp src/catch_setup.cpp src/Art.cpp src/Wall.cpp src/DSLinkedList.h)