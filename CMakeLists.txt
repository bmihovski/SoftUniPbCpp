cmake_minimum_required(VERSION 3.22)
project(PB C)

set(CMAKE_C_STANDARD 23)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# osx specific
set(CMAKE_MACOSX_RPATH TRUE)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_compile_options(--coverage)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
  # Create a custom target to remove stale .gcda files
  file(WRITE "${CMAKE_BINARY_DIR}/cmake_clean_coverage.cmake"
    "file(GLOB_RECURSE gcda_files \"${CMAKE_BINARY_DIR}\" \"*.gcda\")\n"
    "foreach(file \${gcda_files})\n"
    "  file(REMOVE \"\${file}\")\n"
    "endforeach()\n"
  )

  add_custom_target(coverage_clean
    COMMAND ${CMAKE_COMMAND} -P "${CMAKE_BINARY_DIR}/cmake_clean_coverage.cmake"
    COMMENT "Cleaning stale .gcda coverage files"
  )
endif()

include_directories(src)

file(GLOB_RECURSE SOURCES "src/*.c" "src/*.h")
add_library(pb_lib STATIC ${SOURCES})

# Include directories
target_include_directories(pb_lib PUBLIC src)
# Find cmocka using pkg-config (more reliable with brew installations)
find_package(PkgConfig REQUIRED)
pkg_check_modules(CMOCKA REQUIRED cmocka)
# Add error checking for cmocka
if(NOT CMOCKA_FOUND)
    message(FATAL_ERROR "cmocka not found. Please install it: brew install cmocka")
endif()

add_executable(PB ${SOURCES})
# Link pthread library for mutex support
target_link_libraries(PB PRIVATE pb_lib pthread)
# Add tests
file(GLOB_RECURSE TEST_FILES "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.c")
foreach(test_file IN LISTS TEST_FILES)
    get_filename_component(test_name ${test_file} NAME_WE)
    add_executable(${test_name} ${test_file})
    target_link_libraries(${test_name} PRIVATE pb_lib ${CMOCKA_LIBRARIES})
    target_include_directories(${test_name} PRIVATE ${CMOCKA_INCLUDE_DIRS})
    target_link_directories(${test_name} PRIVATE ${CMOCKA_LIBRARY_DIRS})
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
      target_compile_options(${test_name} PRIVATE --coverage)
      target_link_options(${test_name} PRIVATE --coverage)
      add_dependencies(${test_name} coverage_clean)
    endif()
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()

enable_testing()
