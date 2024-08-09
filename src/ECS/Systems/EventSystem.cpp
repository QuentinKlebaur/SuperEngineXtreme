#include "EventSystem.hpp"
#include "UpdateContext.hpp"
#include "IWindow.hpp"

#include <queue>
#include <memory>

void sex::EventSystem::beforeUpdate(UpdateContext const &context)
{
    std::queue<std::unique_ptr<IEvent>> events;

    context.getWindow().fillEvents(events);

    while (!events.empty())
    {
        triggerEvent(*events.front());
        events.pop();
    }
}

void sex::EventSystem::update(UpdateContext const &)
{

}

void sex::EventSystem::afterUpdate(UpdateContext const &)
{

}

void sex::EventSystem::addCallBack(EventType eventType, CallBackFunction &callBack)
{
    _callBacks.emplace(eventType, callBack);
}

void sex::EventSystem::removeCallBack()
{
}

void sex::EventSystem::triggerEvent(IEvent const &event)
{
    auto callBacks = _callBacks.equal_range(event.getType());
    for (auto i = callBacks.first; i != callBacks.second; ++i) {
        i->second(event);
    }
}