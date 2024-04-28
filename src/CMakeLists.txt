set(SOURCES
    main.cpp
    ECS/EntityManager.cpp
    ECS/ComponentManager.cpp
    ECS/SystemManager.cpp
    ECS/Registry.cpp
    ECS/Systems/FallSystem.cpp
    Utils/Chrono.cpp
)

# Add an executable target
add_executable(super_engine_xtreme ${SOURCES})