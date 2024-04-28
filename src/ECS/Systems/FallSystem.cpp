#include "FallSystem.hpp"
#include "Registry.hpp"
#include "PositionComponent.hpp"

namespace sex {
    void FallSystem::update(Registry &registry, int64_t useconds)
    {
        registry.applyOnComponents<PositionComponent>([&](Entity entity, PositionComponent &position){
            position.y = position.y - (0.00001 * useconds);
            if (position.y < 0) {
                _entitiesToDestroy.push_back(entity);
            }
        });
    }

    void FallSystem::beforeUpdate(Registry &registry, int64_t useconds)
    {
    }

    void FallSystem::afterUpdate(Registry &registry, int64_t useconds)
    {
        while (!_entitiesToDestroy.empty()) {
            Entity entity = _entitiesToDestroy.back();
            registry.destoryEntity(entity);
            _entitiesToDestroy.pop_back();
        }
    }
}