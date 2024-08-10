#pragma once

#include <cstdint>

namespace sex {

    enum EventType : uint8_t
    {
        CLICK = 0,
        KEY_PRESSED,
        KEY_RELEASED,
        CLOSE_WINDOW
    };

    struct IEvent {
        public:
            virtual ~IEvent() {};

            virtual EventType getType() const = 0;
    };
}