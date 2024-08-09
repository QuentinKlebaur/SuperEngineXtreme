#include "RenderSystem.hpp"
#include "DrawableComponent.hpp"
#include "Registry.hpp"
#include "IWindow.hpp"
#include "PositionComponent.hpp"
#include "Color.hpp"
#include "UpdateContext.hpp"

sex::RenderSystem::RenderSystem(IWindow *window) : _window{window}
{
}

void sex::RenderSystem::beforeUpdate(UpdateContext const &context)
{
    _window->clear({255, 255, 255});
}

void sex::RenderSystem::update(UpdateContext const &context)
{
    context.getRegistry().applyOnComponents<DrawableComponent>([&](Entity entity, DrawableComponent &drawable){
        PositionComponent *position = context.getRegistry().getComponent<PositionComponent>(entity);

        drawable.get()->setPosition(*position);
        drawable.get()->draw(_window);
    });
}

void sex::RenderSystem::afterUpdate(UpdateContext const &context)
{
    _window->display();
}