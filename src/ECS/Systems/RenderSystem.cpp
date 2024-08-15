#include "RenderSystem.hpp"
#include "DrawableComponent.hpp"
#include "Registry.hpp"
#include "IWindow.hpp"
#include "PositionComponent.hpp"
#include "Color.hpp"
#include "UpdateContext.hpp"

sex::RenderSystem::RenderSystem()
{
}

void sex::RenderSystem::beforeUpdate(UpdateContext &context)
{
    context.getWindow().clear({255, 255, 255});
}

void sex::RenderSystem::update(UpdateContext &context)
{
    context.getRegistry().applyOnComponents<DrawableComponent>([&](Entity entity, DrawableComponent &drawable){
        PositionComponent &position = context.getRegistry().getComponent<PositionComponent>(entity);

        drawable.get().setPosition(position);
        drawable.get().draw(context.getWindow());
    });
}

void sex::RenderSystem::afterUpdate(UpdateContext &context)
{
    context.getWindow().display();
}