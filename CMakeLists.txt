cmake_minimum_required(VERSION 3.25.2)

project(
    swft
    VERSION 0.1
    DESCRIPTION "Sound Wave File Transfer"
    LANGUAGES CXX
)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(
    "${PROJECT_SOURCE_DIR}/include/config.h.in"
    "${PROJECT_BINARY_DIR}/include/config.h"
)

# compiler flags
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror")

# fetch latest argparse library
include(FetchContent)
FetchContent_Declare(
    argparse
    GIT_REPOSITORY https://github.com/p-ranav/argparse.git
)
FetchContent_MakeAvailable(argparse)

add_executable(${PROJECT_NAME} src/main.cpp)

# target_link_libraries(${PROJECT_NAME} <library>) must be after add_executable
target_link_libraries(${PROJECT_NAME} argparse)

# include directories (must be after add_executable)
target_include_directories(${PROJECT_NAME} PUBLIC
    "${PROJECT_BINARY_DIR}/include"
    "${PROJECT_SOURCE_DIR}/include"
)

