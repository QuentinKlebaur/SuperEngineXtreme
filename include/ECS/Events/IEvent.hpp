#pragma once

#include <cstdint>

namespace sex {

    enum EventType : uint8_t
    {
        CLICK = 0
    };

    struct IEvent {
        public:
            virtual EventType getType() const = 0;
    };
}