#pragma once

#include "ISystem.hpp"

namespace sex {
    class IWindow;

    class RenderSystem : public ISystem
    {
        public:
            RenderSystem();
            RenderSystem(RenderSystem const &) = delete;
            RenderSystem(RenderSystem const &&) = delete;
            ~RenderSystem() = default;

            void beforeUpdate(UpdateContext &) override;
            void update(UpdateContext &) override;
            void afterUpdate(UpdateContext &) override;
    };
}