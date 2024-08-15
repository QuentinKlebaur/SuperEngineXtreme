#pragma once

#include "Entity.hpp"

#include <vector>

namespace sex
{
    class EntityManager
    {
    public:
        EntityManager() = default;
        EntityManager(EntityManager const&) = delete;
        EntityManager(EntityManager&&) = default;
        ~EntityManager() = default;

        Entity add();
        bool has(Entity entity);
        void destory(Entity entity);
        void destory(std::vector<Entity> const &entities);
        std::vector<Entity> const &get() const;

    private:
        std::vector<Entity> _entities;
        Entity _count{0};
    };
}
