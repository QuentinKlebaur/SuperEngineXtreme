#include "EntityManager.hpp"

#include <algorithm>

namespace sex {
    Entity EntityManager::add()
    {
        while (std::find(_entities.begin(), _entities.end(), _count) != _entities.end()) {
            ++_count;
        }
        _entities.emplace_back(_count);
        return _count++;
    }

    bool EntityManager::has(Entity entity)
    {
        return std::find(_entities.begin(), _entities.end(), entity) != _entities.end();
    }

    void EntityManager::destory(Entity entity)
    {
        auto i = std::find(_entities.begin(), _entities.end(), entity);

        if (i != _entities.end()) {
            _entities.erase(i);
        }
    }

    std::vector<Entity> const &EntityManager::get() const
    {
        return _entities;
    }
}