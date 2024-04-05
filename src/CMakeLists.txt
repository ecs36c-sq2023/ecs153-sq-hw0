cmake_minimum_required(VERSION 3.10)
# Updated to 3.22 to match the cmake version on CSIF
# Defines the minimum required cmake version
# You can check cmake version on your os by typing 
# `cmake --version` on the terminal

project(hw0 VERSION 1.1.0)
# Project Name and Version

set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(LIB_DIR ${PROJECT_SOURCE_DIR}/lib)
set(TEST_DIR ${PROJECT_SOURCE_DIR}/tests)

set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE}
    CACHE STRING "Choose the type of build, options are: None Debug Release asan"
    FORCE)
    
# AddressSanitize
set(CMAKE_C_FLAGS_ASAN
    "-fsanitize=address -fno-optimize-sibling-calls -fsanitize-address-use-after-scope -fno-omit-frame-pointer -g -O1 -Wall -Wextra -Wpedantic -Werror"
    CACHE STRING "Flags used by the C compiler during AddressSanitizer builds."
    FORCE)
set(CMAKE_CXX_FLAGS_ASAN
    "-fsanitize=address -fno-optimize-sibling-calls -fsanitize-address-use-after-scope -fno-omit-frame-pointer -g -O1 -Wall -Wextra -Wpedantic -Werror"
    CACHE STRING "Flags used by the C++ compiler during AddressSanitizer builds."
    FORCE)


include_directories(${INCLUDE_DIR})


add_library(Calculator SHARED
    ${LIB_DIR}/calculator.c
    ${LIB_DIR}/basic.c
    ${LIB_DIR}/fun.c
    ${LIB_DIR}/scientific.c
)

# The code below sets up GoogleTest
# Reference: http://google.github.io/googletest/quickstart-cmake.html

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

enable_testing()

add_executable(CalculatorTests
  ${TEST_DIR}/AutograderTests.cpp
)
target_link_libraries(CalculatorTests
  Calculator
  GTest::gtest_main
)

gtest_discover_tests(CalculatorTests)