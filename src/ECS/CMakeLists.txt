add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Components)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Systems)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Events)

set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/ComponentManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/EntityManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SystemManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Registry.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/UpdateContext.cpp
)

target_sources(${ENGINE_BINARY} PRIVATE ${SRC})