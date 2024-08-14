set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/SceneBase.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DemoMainScene.cpp
)

target_sources(${ENGINE_BINARY} PRIVATE ${SRC})