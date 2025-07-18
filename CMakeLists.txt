cmake_minimum_required(VERSION 3.22)
project(PB)

set(CMAKE_C_STANDARD 23)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(src)

file(GLOB_RECURSE SOURCES "src/*.c" "src/*.h")

add_executable(PB ${SOURCES})
