#include "EventCallBack.hpp"

sex::EventCallBack::EventCallBack(std::function<bool(sex::IEvent const &)> &callBack) : _callBack{callBack}
{
}

bool sex::EventCallBack::operator()(sex::IEvent const &event)
{
    return _callBack(event);
}