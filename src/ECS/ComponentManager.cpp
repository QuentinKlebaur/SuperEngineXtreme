#include "ComponentManager.hpp"
#include "Entity.hpp"

#include <memory>

namespace sex {
    void ComponentManager::destroy(Entity entity)
    {
        for (auto i = _componentsContainers.begin(); i != _componentsContainers.end(); ++i) {
            // TODO find a way to use std::remove instead
            for (auto j = i->second.begin(); j != i->second.end();)
                if (j->first == entity)
                    j = i->second.erase(j);
                else
                    ++j;
        }
    }
}