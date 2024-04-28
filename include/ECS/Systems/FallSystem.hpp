#pragma once

#include "ISystem.hpp"

#include <queue>

namespace sex
{
    class FallSystem : public ISystem
    {
        public:
            FallSystem() = default;
            FallSystem(FallSystem const &) = delete;
            FallSystem(FallSystem const &&) = delete;
            ~FallSystem() = default;

            void beforeUpdate(Registry &registry, int64_t useconds) override;
            void update(Registry &registry, int64_t useconds) override;
            void afterUpdate(Registry &registry, int64_t useconds) override;

        private:
            std::vector<Entity> _entitiesToDestroy;
    };
}