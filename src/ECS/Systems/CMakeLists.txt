set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/VelocitySystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RenderSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/EventSystem.cpp
)

target_sources(${ENGINE_BINARY} PRIVATE ${SRC})