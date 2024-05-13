add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Components)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Systems)

set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/ComponentManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/EntityManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SystemManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Registry.cpp
)

target_sources(${ENGINE_BINARY} PRIVATE ${SRC})