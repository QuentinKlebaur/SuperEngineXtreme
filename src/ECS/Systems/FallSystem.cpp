#include "FallSystem.hpp"
#include "Registry.hpp"
#include "PositionComponent.hpp"
#include "UpdateContext.hpp"

namespace sex {
    void FallSystem::update(UpdateContext const &context)
    {
        context.getRegistry().applyOnComponents<PositionComponent>([&](Entity entity, PositionComponent &position){
            position.y = position.y - (0.0001 * context.getElapsedTime());
            if (position.y < 0) {
                _entitiesToDestroy.push_back(entity);
            }
        });
    }

    void FallSystem::beforeUpdate(UpdateContext const &context)
    {
    }

    void FallSystem::afterUpdate(UpdateContext const &context)
    {
        while (!_entitiesToDestroy.empty()) {
            Entity entity = _entitiesToDestroy.back();
            context.getRegistry().destoryEntity(entity);
            _entitiesToDestroy.pop_back();
        }
    }
}