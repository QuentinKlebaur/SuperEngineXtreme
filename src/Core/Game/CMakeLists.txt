set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/GameBase.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DemoGame.cpp
)

target_sources(${ENGINE_BINARY} PRIVATE ${SRC})