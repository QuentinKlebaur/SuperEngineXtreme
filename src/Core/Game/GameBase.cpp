#include "GameBase.hpp"
#include "IWindow.hpp"
#include "IScene.hpp"
#include "Registry.hpp"


void sex::GameBase::update(IGraphicModule &graphic, uint64_t elapsedTime)
{
    gameUpdate(graphic, elapsedTime);
    for (auto i = _scenes.begin(); i != _scenes.end(); ++i) {
        (*i)->update(graphic, elapsedTime);
    }
}


void sex::GameBase::event(std::vector<std::unique_ptr<IEvent>> const &events)
{
    gameEvent(events);
    for (auto i = _scenes.begin(); i != _scenes.end(); ++i) {
        (*i)->event(events);
    }
}

bool sex::GameBase::isRunning()
{
    return _isRunning;
}

void sex::GameBase::gameUpdate(IGraphicModule &, uint64_t)
{
}

void sex::GameBase::gameEvent(std::vector<std::unique_ptr<IEvent>> const &)
{
}