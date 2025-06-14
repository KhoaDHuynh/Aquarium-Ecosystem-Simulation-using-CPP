cmake_minimum_required(VERSION 3.10)

# TODO : set project name
project(ExampleGTest)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find GTest package
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Include directories
include_directories(include)

# Source files : TODO
add_library(ouput src/math_ops.cpp)

# Test executable : TODO
add_executable(run_tests tests/test_math_ops.cpp)
target_link_libraries(run_tests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} ouput pthread)