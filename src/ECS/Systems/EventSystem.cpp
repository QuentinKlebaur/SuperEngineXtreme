#include "EventSystem.hpp"
#include "UpdateContext.hpp"
#include "IWindow.hpp"

#include <queue>
#include <memory>

void sex::EventSystem::beforeUpdate(UpdateContext &context)
{
}

void sex::EventSystem::update(UpdateContext &)
{

}

void sex::EventSystem::afterUpdate(UpdateContext &)
{

}

void sex::EventSystem::addCallBack(EventType eventType, CallBackFunction callBack)
{
    _callBacks.emplace(eventType, callBack);
}

void sex::EventSystem::removeCallBack()
{
}

void sex::EventSystem::triggerEvents(std::vector<std::unique_ptr<IEvent>> const &events)
{
    for (auto i = events.begin(); i != events.end(); i++) {
        triggerEvent(*i->get());
    }
}

void sex::EventSystem::triggerEvent(IEvent const &event)
{
    auto callBacks = _callBacks.equal_range(event.getType());
    for (auto i = callBacks.first; i != callBacks.second; ++i) {
        i->second(event);
    }
}