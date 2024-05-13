set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/FallSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/RenderSystem.cpp
)

target_sources(${ENGINE_BINARY} PRIVATE ${SRC})