add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Sfml)

set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp
)

target_sources(${ENGINE_BINARY} PRIVATE ${SRC})