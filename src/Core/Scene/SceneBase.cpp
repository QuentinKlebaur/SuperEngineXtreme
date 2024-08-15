#include "SceneBase.hpp"

sex::Registry &sex::SceneBase::getRegistry()
{
    return _registry;
}

void sex::SceneBase::update(IGraphicModule &graphic, int64_t useconds)
{
    updateScene(graphic, useconds);
    _registry.update(graphic, useconds);
}

void sex::SceneBase::updateScene(IGraphicModule &graphic, int64_t useconds)
{
}