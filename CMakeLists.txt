cmake_minimum_required(VERSION 3.22)
project(PB)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(src)

add_executable(PB src/Skeleton/CarMain.cpp src/Skeleton/Car.h)
