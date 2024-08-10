#include "KeyReleasedEvent.hpp"

sex::KeyReleasedEvent::KeyReleasedEvent(KeyCode key) :
    EventBase{sex::EventType::KEY_RELEASED},
    keyCode{key}
{
}