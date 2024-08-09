#pragma once

#include "IEvent.hpp"
#include "Vector2.hpp"

namespace sex {
    struct ClickEvent : IEvent {
        public:
            ClickEvent() = default;
            ClickEvent(Vector2<short> const &);
            ClickEvent(ClickEvent const &) = default;
            ClickEvent(ClickEvent const &&) = delete;
            ~ClickEvent() = default;

            EventType getType() const override;

            Vector2<short> mousePosition;
    };
}