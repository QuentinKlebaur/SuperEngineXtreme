#include "SystemManager.hpp"

namespace sex {
    void SystemManager::update(Registry &registry, int64_t useconds)
    {
        for (auto &system: _systems) {
            system->beforeUpdate(registry, useconds);
            system->update(registry, useconds);
            system->afterUpdate(registry, useconds);
        }
    }
}