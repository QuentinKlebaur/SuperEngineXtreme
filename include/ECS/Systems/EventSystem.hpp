#pragma once

#include "ISystem.hpp"
#include "IEvent.hpp"
#include "EventCallBack.hpp"

#include <functional>
#include <map>
#include <vector>
#include <memory>

namespace sex
{
    class EventSystem : public ISystem
    {
        public:
            EventSystem() = default;
            EventSystem(EventSystem const &) = delete;
            EventSystem(EventSystem const &&) = delete;
            ~EventSystem() = default;

            void beforeUpdate(UpdateContext &) override;
            void update(UpdateContext &) override;
            void afterUpdate(UpdateContext &) override;

            void triggerEvent(IEvent const &);
            void triggerEvents(std::vector<std::unique_ptr<IEvent>> const &);
            void addCallBack(EventType, CallBackFunction);
            void removeCallBack();

        private:
            std::multimap<EventType, EventCallBack> _callBacks;
    };
}