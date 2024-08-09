#pragma once

#include "EventBase.hpp"
#include "Vector2.hpp"

namespace sex {
    struct ClickEvent : public EventBase {
        public:
            ClickEvent() = default;
            ClickEvent(Vector2<short> const &);
            ClickEvent(ClickEvent const &) = default;
            ClickEvent(ClickEvent const &&) = delete;
            ~ClickEvent() = default;

            Vector2<short> mousePosition;
    };
}