#include "VelocitySystem.hpp"
#include "Registry.hpp"
#include "PositionComponent.hpp"
#include "UpdateContext.hpp"
#include "VelocityComponent.hpp"

namespace sex {
    void VelocitySystem::update(UpdateContext &context)
    {
        context.getRegistry().applyOnComponents<PositionComponent>([&](Entity entity, PositionComponent &position){
            VelocityComponent &velocity = context.getRegistry().getComponent<VelocityComponent>(entity);
            position.x += velocity.x * ((double)(context.getElapsedTime()) / 1000000);
            position.y += velocity.y * ((double)(context.getElapsedTime()) / 1000000);
        });
    }

    void VelocitySystem::beforeUpdate(UpdateContext &)
    {
    }

    void VelocitySystem::afterUpdate(UpdateContext &)
    {
    }
}