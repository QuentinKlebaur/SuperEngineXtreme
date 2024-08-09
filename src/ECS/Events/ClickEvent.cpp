#include "ClickEvent.hpp"


sex::ClickEvent::ClickEvent(Vector2<short> const &position) : mousePosition{position}
{

}

sex::EventType sex::ClickEvent::getType() const
{
    return sex::EventType::CLICK;
}