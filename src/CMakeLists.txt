set(SOURCES 
    main.cpp
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/ComponentManager
    ${CMAKE_CURRENT_SOURCE_DIR}/Components
    ${CMAKE_CURRENT_SOURCE_DIR}/Exceptions
    ${CMAKE_CURRENT_SOURCE_DIR}/Utils
)

# Add an executable target
add_executable(super_engine_xtreme ${SOURCES})