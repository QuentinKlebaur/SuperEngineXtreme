#include "KeyPressedEvent.hpp"

sex::KeyPressedEvent::KeyPressedEvent(KeyCode key) :
    EventBase{sex::EventType::KEY_PRESSED},
    keyCode{key}
{
}