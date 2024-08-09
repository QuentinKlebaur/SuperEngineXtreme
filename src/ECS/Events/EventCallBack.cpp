#include "EventCallBack.hpp"

sex::EventCallBack::EventCallBack(CallBackFunction &callBack) : _callBack{callBack}
{
}

bool sex::EventCallBack::operator()(sex::IEvent const &event)
{
    return _callBack(event);
}