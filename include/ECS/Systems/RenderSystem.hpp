#pragma once

#include "ISystem.hpp"

namespace sex {
    class IWindow;

    class RenderSystem : public ISystem
    {
        public:
            RenderSystem(IWindow *window=nullptr);
            RenderSystem(RenderSystem const &) = delete;
            RenderSystem(RenderSystem const &&) = delete;
            ~RenderSystem() = default;

            void beforeUpdate(UpdateContext const &) override;
            void update(UpdateContext const &) override;
            void afterUpdate(UpdateContext const &) override;

        private:
            IWindow *_window;
    };
}