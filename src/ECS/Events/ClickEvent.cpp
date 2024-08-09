#include "ClickEvent.hpp"

sex::ClickEvent::ClickEvent(Vector2<short> const &position) :
    EventBase{sex::EventType::CLICK},
    mousePosition{position}
{

}