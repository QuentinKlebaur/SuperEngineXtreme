set(ENGINE_BINARY super_engine_xtreme)

add_executable(${ENGINE_BINARY})

set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_sources(${ENGINE_BINARY} PRIVATE ${SRC})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ECS)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Utils)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Graphic)

target_link_libraries(super_engine_xtreme PRIVATE sex_graphic_sfml)