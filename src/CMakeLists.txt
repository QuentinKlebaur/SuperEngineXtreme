set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ECS/EntityManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ECS/ComponentManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ECS/SystemManager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ECS/Registry.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ECS/Systems/FallSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ECS/Systems/RenderSystem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ECS/Components/DrawableComponent.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Utils/Chrono.cpp
)

set(GRAPHICAL_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Graphic/Color.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Graphic/Sfml/SfmlGraphicModule.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Graphic/Sfml/SfmlWindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Graphic/Sfml/SfmlDrawable.cpp
)

# Add an executable target
add_executable(super_engine_xtreme ${SOURCES} ${GRAPHICAL_SOURCES})

target_link_libraries(super_engine_xtreme PRIVATE sfml-graphics sfml-audio sfml-window sfml-system)