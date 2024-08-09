#pragma once

#include "SystemManager.hpp"
#include "ComponentManager.hpp"
#include "EntityManager.hpp"

namespace sex {
    class IGraphicModule;
    class Registry {
        public:
            Registry() = default;
            Registry(Registry const&) = delete;
            Registry(Registry&&) = default;
            ~Registry() = default;

            // Entities

            Entity createEntity();
            bool hasEntity(Entity entity);
            void destoryEntity(Entity entity);
            std::vector<Entity> const &getEntities() const;

            // Components

            template<typename T, typename... Args>
            T *addComponent(Entity entity, Args... args)
            {
                return _componentManager.add<T>(entity, args...);
            }

            template<typename T>
            T *getComponent(Entity entity)
            {
                return _componentManager.get<T>(entity);
            }

            template<typename T>
            bool hasComponent(Entity entity)
            {
                return _componentManager.has<T>(entity);
            }

            template<typename T>
            void applyOnComponents(std::function<void (Entity, T &)> function)
            {
                _componentManager.apply<T>(function);
            }

            template<typename T>
            void destroyComponent(Entity entity)
            {
                _componentManager.destroy<T>(entity);
            }

            void destroyAllComponents(Entity entity);

            // Systems

            template<typename T, typename... Args>
            void addSystem(Args... args)
            {
                _systemManager.add<T>(args...);
            }

            template<typename T>
            T *getSystem()
            {
                return _systemManager.get<T>();
            }

            void update(IGraphicModule &graphic, int64_t useconds);

        private:
            SystemManager _systemManager;
            EntityManager _entityManager;
            ComponentManager _componentManager;
    };
}