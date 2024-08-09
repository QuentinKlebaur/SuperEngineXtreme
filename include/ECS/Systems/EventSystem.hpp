#pragma once

#include "ISystem.hpp"
#include "IEvent.hpp"
#include "EventCallBack.hpp"

#include <functional>
#include <map>

namespace sex
{
    class EventSystem : public ISystem
    {
        public:
            EventSystem() = default;
            EventSystem(EventSystem const &) = delete;
            EventSystem(EventSystem const &&) = delete;
            ~EventSystem() = default;

            void beforeUpdate(UpdateContext const &) override;
            void update(UpdateContext const &) override;
            void afterUpdate(UpdateContext const &) override;

            void triggerEvent(IEvent const &);
            void addCallBack(EventType, CallBackFunction);
            void removeCallBack();

        private:
            std::multimap<EventType, EventCallBack> _callBacks;
    };
}