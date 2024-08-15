
#include "ComponentManager.hpp"
#include "Entity.hpp"

#include <memory>
#include <algorithm>

namespace sex {
    void ComponentManager::destroy(Entity entity)
    {
        for (auto i = _componentsContainers.begin(); i != _componentsContainers.end(); ++i) {
            for (auto j = i->second.begin(); j != i->second.end();)
                if (j->first == entity)
                    j = i->second.erase(j);
                else
                    ++j;
        }
    }

    void ComponentManager::destroy(std::vector<Entity> const &entities)
    {
        for (auto i = _componentsContainers.begin(); i != _componentsContainers.end(); ++i) {
            for (auto j = i->second.begin(); j != i->second.end();)
                if (std::find(entities.begin(), entities.end(), j->first) != entities.end())
                    j = i->second.erase(j);
                else
                    ++j;
        }
    }
}