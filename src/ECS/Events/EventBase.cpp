#include "EventBase.hpp"

sex::EventBase::EventBase(EventType eventType) : _eventType{eventType}
{
}

sex::EventType sex::EventBase::getType() const
{
    return _eventType;
}