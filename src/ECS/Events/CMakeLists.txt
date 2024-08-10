set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/EventBase.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ClickEvent.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/CloseWindowEvent.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/KeyPressedEvent.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/KeyReleasedEvent.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/EventCallBack.cpp
)

target_sources(${ENGINE_BINARY} PRIVATE ${SRC})