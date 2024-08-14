add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Game)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Scene)

set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/Core.cpp
)

target_sources(${ENGINE_BINARY} PRIVATE ${SRC})