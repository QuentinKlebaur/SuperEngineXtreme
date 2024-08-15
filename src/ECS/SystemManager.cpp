#include "SystemManager.hpp"
#include "UpdateContext.hpp"

namespace sex {
    void SystemManager::update(UpdateContext &context)
    {
        for (auto &system: _systems) {
            system->beforeUpdate(context);
            system->update(context);
            system->afterUpdate(context);
        }
    }
}