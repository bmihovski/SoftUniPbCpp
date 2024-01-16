# PB Project

This project is designed to automate the testing and development of exercise solutions for the SoftUni C++ programming basics course. The project is built with C++ and uses CMake as a build system and Google Test (gtest) as a testing framework.

## Dependencies

- CMake (minimum version 3.26)
- Google Test (gtest)

## Structure

The project is structured as follows:

- `src/main.cpp`: This is where the solution for the coding exercise is implemented. The solution must be implemented in the `process` method which accepts standard input (stdin) and produces standard output (stdout).
- `tests/main_test.cpp`: This file contains the unit tests for the `process` method. We use Google Test's `TestWithParam` to be able to have multiple test scenarios. The `TestParam` struct accepts the test input and expected test result.
- `CMakeLists.txt`: This file contains the CMake configuration for the project. It specifies the minimum required version of CMake, the project name, the C++ standard, and the dependencies of the project. It also sets up the executables for the main application and the tests.

## Usage

To use this project, follow these steps:

1. Implement your solution in the `process` method in `src/main.cpp`.
2. Add your test scenarios in `tests/main_test.cpp` by adding instances of `TestParam` to the `::testing::Values` in the `INSTANTIATE_TEST_SUITE_P` macro.
3. Build the project using CMake.
4. Run the tests to verify your solution.
5. Once your solution is ready and all tests pass, copy the full content of `src/main.cpp` and paste it into the SoftUni judge system.

## Ignored Files

The following files and directories are ignored by git:

- `/.idea/`
- `/cmake-build-debug/`
- `/main`

Please note that these files and directories are specific to the development environment and should not be included in the version control system.

## Note

This project is designed to automate the testing process and make it easier to develop solutions for the SoftUni C++ programming basics course. It is not intended to be a complete solution for all coding exercises. Always refer to the specific requirements of each exercise when implementing your solution.