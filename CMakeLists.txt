cmake_minimum_required(VERSION 3.13)

project(gtest_prac LANGUAGES CXX)

# set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# place binaries and libraries according to GNU standards
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY /workspaces/gtest_practice/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY /workspaces/gtest_practice/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY /workspaces/gtest_practice/output)

# we cannot analyse results without gcov
#find_program(GCOV_PATH gcov)
#if(NOT GCOV_PATH)
#  message(FATAL_ERROR "Code coverage analysis requires gcov!")
#endif()

#add_subdirectory(src)
#add_library(gtest_prac src/unit_test.cpp)

enable_testing()
#find_package(GTest REQUIRED) # Find the google testing framework on your system
#include_directories(${GTEST_INCLUDE_DIRS})
#target_link_libraries(gtest_prac gtest gtest_main) # Replace ${PROJECT_NAME} with your target name
#add_subdirectory(test)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
add_executable(gtest_prac ${CMAKE_CURRENT_SOURCE_DIR}/src/unit_test.cpp ${CMAKE_CURRENT_SOURCE_DIR}/test/test_unit_test.cpp)
target_link_libraries(gtest_prac gtest gtest_main gmock_main pthread)