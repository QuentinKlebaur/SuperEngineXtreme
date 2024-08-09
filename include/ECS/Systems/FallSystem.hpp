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

            void beforeUpdate(UpdateContext const &) override;
            void update(UpdateContext const &) override;
            void afterUpdate(UpdateContext const &) override;

        private:
            std::vector<Entity> _entitiesToDestroy;
    };
}