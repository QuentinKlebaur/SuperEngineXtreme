#pragma once

#include "EventBase.hpp"
#include "Vector2.hpp"
#include "KeyCode.hpp"

namespace sex {
    struct KeyReleasedEvent : public EventBase {
        public:
            KeyReleasedEvent() = delete;
            KeyReleasedEvent(KeyCode);
            KeyReleasedEvent(KeyReleasedEvent const &) = default;
            KeyReleasedEvent(KeyReleasedEvent const &&) = delete;
            ~KeyReleasedEvent() = default;

            KeyCode keyCode;
    };
}