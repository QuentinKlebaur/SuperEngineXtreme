#pragma once

#include "EventBase.hpp"
#include "Vector2.hpp"
#include "KeyCode.hpp"

namespace sex {
    struct KeyPressedEvent : public EventBase {
        public:
            KeyPressedEvent() = delete;
            KeyPressedEvent(KeyCode);
            KeyPressedEvent(KeyPressedEvent const &) = default;
            KeyPressedEvent(KeyPressedEvent const &&) = delete;
            ~KeyPressedEvent() = default;

            KeyCode keyCode;
    };
}