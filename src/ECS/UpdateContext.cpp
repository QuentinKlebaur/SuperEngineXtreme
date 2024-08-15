#include "UpdateContext.hpp"
#include "Registry.hpp"
#include "IGraphicModule.hpp"
#include "IWindow.hpp"

sex::UpdateContext::UpdateContext(IGraphicModule &graphic, Registry &registry, int64_t elapsedTime) :
    _graphicModule{graphic},
    _registry{registry},
    _elapsedTime{elapsedTime}
{
}

sex::UpdateContext::~UpdateContext()
{
    _registry.destoryEntities(_entitiesToRemove);
}

sex::Registry &sex::UpdateContext::getRegistry() const
{
    return _registry;
}

sex::IGraphicModule &sex::UpdateContext::getGraphicModule() const
{
    return _graphicModule;
}

sex::IWindow &sex::UpdateContext::getWindow() const
{
    return _graphicModule.window();
}

int64_t sex::UpdateContext::getElapsedTime() const
{
    return _elapsedTime;
}

void sex::UpdateContext::removeEntity(Entity entity)
{
    _entitiesToRemove.push_back(entity);
}