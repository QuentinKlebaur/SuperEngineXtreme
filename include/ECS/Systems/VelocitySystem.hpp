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

            void beforeUpdate(UpdateContext &) override;
            void update(UpdateContext &) override;
            void afterUpdate(UpdateContext &) override;
    };
}