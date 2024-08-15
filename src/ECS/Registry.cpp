#include "Registry.hpp"
#include "IGraphicModule.hpp"
#include "UpdateContext.hpp"

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

    void Registry::destoryEntities(std::vector<Entity> const &entities)
    {
        _entityManager.destory(entities);
        _componentManager.destroy(entities);
    }

    std::vector<Entity> const &Registry::getEntities() const
    {
        return _entityManager.get();
    }

    void Registry::destroyAllComponents(Entity entity)
    {
        _componentManager.destroy(entity);
    }

    void Registry::update(IGraphicModule &graphic, int64_t useconds)
    {
        UpdateContext context{graphic, *this, useconds};

        _systemManager.update(context);
    }
}