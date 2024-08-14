#include "GameBase.hpp"
#include "IWindow.hpp"
#include "IScene.hpp"
#include "Registry.hpp"

sex::GameBase::GameBase(IGraphicModule &graphic) : _graphicModule{graphic}
{
}

void sex::GameBase::run()
{
    _chrono.reset();
    while (_graphicModule.window().isOpen() && _running)
    {
        int64_t elapsedTime = _chrono.reset();

        for (auto i = _scenes.begin(); i != _scenes.end(); ++i) {
            (*i)->getRegistry().update(_graphicModule, elapsedTime);
            (*i)->update(_graphicModule, elapsedTime);
        }
    }
}