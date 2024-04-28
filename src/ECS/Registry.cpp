#include "Registry.hpp"

namespace sex {
    Entity Registry::createEntity()
    {
        return _entityManager.add();
    }

    bool Registry::hasEntity(Entity entity)
    {
        return _entityManager.has(entity);
    }

    void Registry::destoryEntity(Entity entity)
    {
        _entityManager.destory(entity);
        _componentManager.destroy(entity);
    }

    std::vector<Entity> const &Registry::getEntities() const
    {
        return _entityManager.get();
    }

    void Registry::destroyAllComponents(Entity entity)
    {
        _componentManager.destroy(entity);
    }

    void Registry::update(int64_t useconds)
    {
        _systemManager.update(*this, useconds);
    }
}