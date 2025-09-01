cmake_minimum_required(VERSION 4.0)
project(PB)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_COMPILER_FLAGS "${CMAKE_C_COMPILER_FLAGS} -Wall -Wextra -pedantic")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(src)

file(GLOB_RECURSE SOURCES "src/Skeleton/*.cpp" "src/Skeleton/*.h")

add_executable(PB ${SOURCES})
