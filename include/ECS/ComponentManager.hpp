#pragma once

#include "IComponent.hpp"
#include "NotAComponentException.hpp"
#include "ComponentContainerDoesNotExistException.hpp"
#include "Entity.hpp"

#include <unordered_map>
#include <vector>
#include <cstddef>
#include <memory>
#include <typeinfo>
#include <iostream>
#include <functional>

#define Type std::string
#define ComponentContainer std::unordered_map<Entity, std::unique_ptr<IComponent>>

namespace sex {
    class ComponentManager {
        public:
            ComponentManager() : _componentsContainers{} {}
            ComponentManager(ComponentManager const &) = delete;
            ComponentManager(ComponentManager const &&) = delete;
            ~ComponentManager() = default;

            template<typename T, typename... Args>
            T *add(Entity entity, Args... args)
            {
                ComponentContainer &componentContainer = getComponentContainer<T>();

                auto iterator = componentContainer.emplace(entity, std::make_unique<T>(args...)).first;
                return static_cast<T*>(iterator->second.get());
            }

            template<typename T>
            T *get(Entity entity)
            {
                ComponentContainer &componentContainer = getComponentContainer<T>();

                auto iterator = componentContainer.find(entity);
                if (iterator == componentContainer.end()) {
                    return nullptr;
                }
                return static_cast<T*>(iterator->second.get());
            }

            template<typename T>
            bool has(Entity entity)
            {
                ComponentContainer &componentContainer = getComponentContainer<T>();

                auto iterator = componentContainer.find(entity);
                if (iterator == componentContainer.end()) {
                    return nullptr;
                }
                return static_cast<T*>(iterator->second.get());
            }

            template<typename T>
            void destroy(Entity entity)
            {
                ComponentContainer &componentContainer = getComponentContainer<T>();

                // TODO erase
                std::remove(componentContainer.begin(), componentContainer.end(), entity);
            }

            void destroy(Entity entity);

            template<typename T>
            void apply(std::function<void(Entity, T &)> function)
            {
                ComponentContainer &componentContainer = getComponentContainer<T>();

                for (auto &component: componentContainer) {
                    function(component.first, *(static_cast<T*>(component.second.get())));
                }
            }

            template<typename T>
            static Type getType() noexcept
            {
                return typeid(T).name();
            }

        private:
            template<typename T>
            ComponentContainer &createComponentContainer()
            {
                _componentsContainers.emplace(getType<T>(), ComponentContainer{});
                auto ret = _componentsContainers.find(getType<T>());
                if (ret == _componentsContainers.end()) {
                    throw std::exception(); // TODO find a better error management
                }
                return ret->second;
            }

            template<typename T>
            ComponentContainer &getComponentContainer()
            {
                Type componentTypeInfo = getType<T>();

                auto iterator = _componentsContainers.find(componentTypeInfo);
                if (iterator == _componentsContainers.end()) {
                    return createComponentContainer<T>();
                }
                return iterator->second;
            }
            std::unordered_map<Type, ComponentContainer> _componentsContainers;
    };
}