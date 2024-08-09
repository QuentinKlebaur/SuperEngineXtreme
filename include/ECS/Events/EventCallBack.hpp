#include "IEvent.hpp"

#include <functional>

namespace sex {
    class EventCallBack {
        public:
            EventCallBack() = delete;
            EventCallBack(std::function<bool(IEvent const &)> &callBack);
            EventCallBack(EventCallBack const &) = default;
            EventCallBack(EventCallBack const &&) = delete;
            ~EventCallBack() = default;

            bool operator()(IEvent const &);

        private:
            std::function<bool(IEvent const &)> _callBack;
    };
}