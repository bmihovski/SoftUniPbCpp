cmake_minimum_required(VERSION 3.26)
project(PB)

set(CMAKE_CXX_STANDARD 17)

# Find the GoogleTest package
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS} src)

add_executable(PB src/main.cpp)

# Create a separate executable for the tests
add_executable(PbTest tests/main_test.cpp)

# Add a compile definition to the test executable
target_compile_definitions(PbTest PRIVATE TESTING)

# Link the GoogleTest package with our executable
target_link_libraries(PbTest ${GTEST_LIBRARIES} pthread)
