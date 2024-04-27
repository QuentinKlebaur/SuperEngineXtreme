set(SOURCES
    main.cpp
    ECS/EntityManager.cpp
    ECS/SystemManager.cpp
    ECS/Registry.cpp
)

# Add an executable target
add_executable(super_engine_xtreme ${SOURCES})