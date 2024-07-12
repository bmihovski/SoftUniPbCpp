cmake_minimum_required(VERSION 3.22)
project(PB)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(src)

file(GLOB_RECURSE SOURCES "src/Skeleton/*.cpp" "src/Skeleton/*.h")

add_executable(PB ${SOURCES})
