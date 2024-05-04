#include "RenderSystem.hpp"
#include "DrawableComponent.hpp"
#include "Registry.hpp"
#include "IWindow.hpp"
#include "PositionComponent.hpp"
#include "Color.hpp"

sex::RenderSystem::RenderSystem(IWindow *window) : _window{window}
{
}

void sex::RenderSystem::beforeUpdate(Registry &registry, int64_t useconds)
{
    _window->clear({255, 255, 255});
}

void sex::RenderSystem::update(Registry &registry, int64_t useconds)
{
    registry.applyOnComponents<DrawableComponent>([&](Entity entity, DrawableComponent &drawable){
        PositionComponent *position = registry.getComponent<PositionComponent>(entity);

        drawable.get()->setPosition(*position);
        drawable.get()->draw(_window);
    });
}

void sex::RenderSystem::afterUpdate(Registry &registry, int64_t useconds)
{
    _window->display();
}