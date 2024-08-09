#include "EventBase.hpp"
#include "Vector2.hpp"

namespace sex {
    class CloseWindowEvent : public EventBase
    {
        public:
            CloseWindowEvent();
            CloseWindowEvent(CloseWindowEvent const &) = default;
            CloseWindowEvent(CloseWindowEvent const &&) = delete;
            ~CloseWindowEvent() = default;
    };
}