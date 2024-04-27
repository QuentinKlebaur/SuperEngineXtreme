#pragma once

#include "SystemManager.hpp"
#include "ComponentManager.hpp"
#include "EntityManager.hpp"

namespace sex {
    class Registry {
        public:
        Registry() = default;
        Registry(Registry const&) = delete;
        Registry(Registry&&) = default;
        ~Registry() = default;

        private:
            SystemManager _systemManager;
            ComponentManager _componentManager;
            EntityManager _entityManager;
    };
}