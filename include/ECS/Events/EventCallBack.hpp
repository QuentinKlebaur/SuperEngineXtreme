#include "IEvent.hpp"

#include <functional>

namespace sex {
    using CallBackFunction = std::function<bool(IEvent const &)>;
    class EventCallBack {
        public:
            EventCallBack() = delete;
            EventCallBack(CallBackFunction callBack);
            EventCallBack(EventCallBack const &) = default;
            EventCallBack(EventCallBack const &&) = delete;
            ~EventCallBack() = default;

            bool operator()(IEvent const &);

        private:
            CallBackFunction _callBack;
    };
}