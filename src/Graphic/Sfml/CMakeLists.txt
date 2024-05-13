set(SFML_VERSION "2.5.1")

set(FETCHCONTENT_BASE_DIR external)

FetchContent_Declare(
    SFML
    URL https://www.sfml-dev.org/files/SFML-${SFML_VERSION}-sources.zip
)
FetchContent_MakeAvailable(SFML)

set(SFML_GRAPHIC_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/SfmlDrawable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SfmlGraphicModule.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SfmlWindow.cpp
)

add_library(sex_graphic_sfml STATIC ${SFML_GRAPHIC_SOURCES})

target_link_libraries(sex_graphic_sfml PRIVATE sfml-graphics sfml-audio sfml-window sfml-system)