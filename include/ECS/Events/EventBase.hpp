#pragma once

#include "IEvent.hpp"

namespace sex {
    class EventBase : IEvent
    {
        public:
            EventBase() = delete;
            EventBase(EventBase const &) = default;
            EventBase(EventBase const &&) = delete;
            EventBase(EventType);
            ~EventBase() = default;

            EventType getType() const override;

        private:
            EventType _eventType;
    };
}