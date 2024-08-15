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

    void EntityManager::destory(std::vector<Entity> const &entities)
    {
        _entities.erase(std::remove_if(_entities.begin(), _entities.end(), [&](Entity entity) {
            return std::find(entities.begin(), entities.end(), entity) != entities.end();
        }), _entities.end());

    }

    std::vector<Entity> const &EntityManager::get() const
    {
        return _entities;
    }
}