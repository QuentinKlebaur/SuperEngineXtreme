#pragma once

#include "Entity.hpp"

#include <cstdint>
#include <vector>

namespace sex {
    class IGraphicModule;
    class IWindow;
    class Registry;

    class UpdateContext
    {
        public:
            UpdateContext() = default;
            UpdateContext(IGraphicModule &, Registry &, int64_t elapsedTime);
            UpdateContext(UpdateContext const &) = default;
            UpdateContext(UpdateContext const &&) = delete;
            ~UpdateContext();

            Registry &getRegistry() const;
            IGraphicModule &getGraphicModule() const;
            IWindow &getWindow() const;
            int64_t getElapsedTime() const;
            void removeEntity(Entity);

        private:
            std::vector<Entity> _entitiesToRemove;
            IGraphicModule &_graphicModule;
            Registry &_registry;
            int64_t _elapsedTime;
    };
}