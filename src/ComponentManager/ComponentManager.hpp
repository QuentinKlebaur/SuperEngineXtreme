#pragma once

#include "IComponent.hpp"
#include "NotAComponentException.hpp"
#include "ComponentContainerDoesNotExistException.hpp"

#include <unordered_map>
#include <vector>
#include <cstddef>
#include <memory>
#include <typeinfo>
#include <iostream>

#define Type std::string

/*struct TypeHasher
{
    TypeHasher() {}
    size_t operator()(const Type& t) const
    {
        return std::hash<std::string>{}(t.name());
    }
};*/

#define Entity std::size_t
#define ComponentContainer std::unordered_map<Entity, std::unique_ptr<IComponent>>

namespace sex {
    class ComponentManager {
        public:
            ComponentManager() : _componentsContainers{} {}
            ComponentManager(ComponentManager const &) = delete;
            ComponentManager(ComponentManager const &&) = delete;

            ~ComponentManager() {}

            template<typename T>
            void addComponent(Entity entity, T *component)
            {
                ComponentContainer *componentContainer;

                try {
                    componentContainer = getComponentContainer<T>();
                } catch (ComponentContainerDoesNotExistException e) {
                    try {
                        std::cout << "Component Container : [" << getType<T>() << "] need to be created" << std::endl;
                        componentContainer = createComponentContainer<T>();
                        std::cout << "Component Container : [" << getType<T>() << "] was created" << std::endl;
                    } catch (std::exception e) {
                        return;
                    }
                };
                componentContainer->insert(std::pair<Entity, std::unique_ptr<IComponent>>{entity, component});
            }

            template<typename T>
            T *getComponent(Entity entity)
            {
                ComponentContainer *componentContainer;

                try {
                    componentContainer = getComponentContainer<T>();
                } catch (ComponentContainerDoesNotExistException e) {
                    return nullptr;
                };
                auto iterator = componentContainer->find(entity);
                if (iterator == componentContainer->end()) {
                    return nullptr;
                }
                return static_cast<T*>(iterator->second.get());
            }
            
            template<typename T>
            static Type getType() noexcept
            {
                return typeid(T).name();
            }

        private:
            template<typename T>
            ComponentContainer *createComponentContainer()
            {
                try {
                    getComponentContainer<T>();
                } catch (ComponentContainerDoesNotExistException e) {
                    _componentsContainers.insert(std::pair<Type, ComponentContainer>{getType<T>(), ComponentContainer{}});
                    auto ret = _componentsContainers.find(getType<T>());
                    if (ret ==_componentsContainers.end()) {
                        throw std::exception(); // TODO find a better error management
                    }
                    return &(ret->second);
                };
                std::cout << "Component Container was not created" << std::endl;
                throw std::exception(); // TODO find a better error management
            }

            template<typename T>
            ComponentContainer *getComponentContainer()
            {
                Type componentTypeInfo = getType<T>();

                std::cout << "Searched Type: " << componentTypeInfo << std::endl;
                auto iterator = _componentsContainers.find(componentTypeInfo);
                if (iterator == _componentsContainers.end()) {
                    throw ComponentContainerDoesNotExistException();
                }
                return &(iterator->second);
            }

            std::unordered_map<Type, ComponentContainer> _componentsContainers;
            std::vector<Entity> _entities;
    };
}