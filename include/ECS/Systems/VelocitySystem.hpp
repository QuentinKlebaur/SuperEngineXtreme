#pragma once

#include "ISystem.hpp"

#include <queue>

namespace sex
{
    class VelocitySystem : public ISystem
    {
        public:
            VelocitySystem() = default;
            VelocitySystem(VelocitySystem const &) = delete;
            VelocitySystem(VelocitySystem const &&) = delete;
            ~VelocitySystem() = default;

            void beforeUpdate(UpdateContext const &) override;
            void update(UpdateContext const &) override;
            void afterUpdate(UpdateContext const &) override;
    };
}