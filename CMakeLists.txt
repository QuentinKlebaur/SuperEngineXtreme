# CMake version
cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

# Project name
project(SuperEngineXtreme)

# includes
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include/ECS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/ECS/Components
    ${CMAKE_CURRENT_SOURCE_DIR}/include/ECS/Systems
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Components
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Exceptions
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Utils
)

# Include subdirectories
add_subdirectory(src)