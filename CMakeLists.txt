# CMake version
cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

# Project name
project(SuperEngineXtreme)

# Compile options
add_compile_options(-Wall -Wextra -Wpedantic -g)

# Libraries
include(FetchContent)

set(SFML_VERSION "2.5.1")

set(FETCHCONTENT_BASE_DIR "${CMAKE_CURRENT_BINARY_DIR}/external")

if(NOT TARGET sfml-graphics)
FetchContent_Declare(
    SFML
    URL https://www.sfml-dev.org/files/SFML-${SFML_VERSION}-sources.zip
)
FetchContent_MakeAvailable(SFML)
endif()

# includes
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include/ECS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/ECS/Components
    ${CMAKE_CURRENT_SOURCE_DIR}/include/ECS/Systems
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Components
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Exceptions
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Utils
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Graphic
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Graphic/Sfml
)

# Include subdirectories
add_subdirectory(src)